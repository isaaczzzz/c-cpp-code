#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

union MyByte
{
    unsigned char bvalue;
    struct mytype
    {
        BYTE bit0 : 1;
        BYTE bit1 : 1;
        BYTE bit2 : 1;
        BYTE bit3 : 1;
        BYTE bit4 : 1;
        BYTE bit5 : 1;
        BYTE bit6 : 1;
        BYTE bit7 : 1;
    } type;
};

int main(void)
{
    // BMP文件的数据按照从文件头开始的先后顺序分为四个部分：
    // BITMAPFILEHEADER,位图文件头(bmp file header)：  提供文件的格式、大小等信息
    // BITMAPINFOHEADER,位图信息头(bitmap information)：提供图像数据的尺寸、位平面数、压缩方式、颜色索引等信息
    // RGBQUAD,调色板(color palette)：可选，如使用索引来表示图像，调色板就是索引与其对应的颜色的映射表
    //位图数据(bitmap data)：图像数据区
    MyByte my;
    my.bvalue = 0xF1;
    my.type.bit1;
    fstream fs;
    string path = "tmp.bmp";
    fs.open(path, ios::in | ios::binary);
    if (!fs.is_open())
    {
        return -1;
    }

    BITMAPFILEHEADER bmpFileHeader = {0};
    //读取header
    // sizeof(BITMAPFILEHEADER)在当前PC上大小为14，而不是16，如果是16需要注意对齐问题
    fs.read((char *)&bmpFileHeader, sizeof(BITMAPFILEHEADER));
    //文件标识符，必须为"BM"，小端模式，即0x4d42 才是Windows位图文件
    if (bmpFileHeader.bfType != 0x4D42)
    {
        return -1;
    };

    BITMAPINFOHEADER bmpInfoHeader = {0};
    fs.read((char *)&bmpInfoHeader, sizeof(BITMAPINFOHEADER));

    if (bmpInfoHeader.biBitCount == 1)
    {
        /*解析二值图像的调色板*/
        /*二值图像的调色板只有黑白两种颜色，即这边的pRGB只有两个元素，(0,0,0,0)和(255,255,255,0)*/
        /*第四个值保留，一般用于阿尔法通道*/
        /*biBitCount 小于等于8的情况下，都存有调色板，数据区对应的存储在调色板中的索引值，超过8时，bmp中不存储调色板信息*/
        int size = 1 << bmpInfoHeader.biBitCount;
        RGBQUAD *pRGB = new RGBQUAD[size];

        for (int i = 0; i < size; ++i)
        {
            fs.read((char *)&pRGB[i], sizeof(RGBQUAD));
        }

        /*计算每行读取的字节数。每行数据4字节对齐，不足4字节的会自动补齐*/
        int lineBytes = ((bmpInfoHeader.biWidth * bmpInfoHeader.biBitCount + 31) / 8) / 4 * 4;
        std::fstream fsout;
        vector<BYTE *> v;
        for (int j = 0; j < bmpInfoHeader.biHeight; ++j)
        {
            BYTE *buf = new BYTE[lineBytes];
            memset(buf, 0, lineBytes);
            fs.read((char *)buf, lineBytes);
            v.push_back(buf);
        }

        fsout.open("t1022.txt", ios::out);
        //默认bmp位图数据存储是相反的，即上面的图像数据存储在数据末端。
        //读取时需要颠倒下。

        int map[65][17][9]; //行，列，bit;
        for (int j = bmpInfoHeader.biHeight - 1; j >= 0; --j)
        {
            BYTE *buf = v.at(j);
            for (int jj = 0; jj < lineBytes; ++jj)
            {
                MyByte b;
                b.bvalue = buf[jj];
                // 注意字节序，前面的数据存储在高bit位。每比特存储的实质是调色板的索引值，即0表示pRGB[0]的值，这里表示(0,0,0)即黑色
                map[bmpInfoHeader.biHeight - j][jj][0] = (unsigned int)b.type.bit7; //行从1开始
                map[bmpInfoHeader.biHeight - j][jj][1] = (unsigned int)b.type.bit6;
                map[bmpInfoHeader.biHeight - j][jj][2] = (unsigned int)b.type.bit5;
                map[bmpInfoHeader.biHeight - j][jj][3] = (unsigned int)b.type.bit4;
                map[bmpInfoHeader.biHeight - j][jj][4] = (unsigned int)b.type.bit3;
                map[bmpInfoHeader.biHeight - j][jj][5] = (unsigned int)b.type.bit2;
                map[bmpInfoHeader.biHeight - j][jj][6] = (unsigned int)b.type.bit1;
                map[bmpInfoHeader.biHeight - j][jj][7] = (unsigned int)b.type.bit0;
            }
        }

        int map2[9][129];
        int num, bin, i, row, col = 1;
        for (int j = 0; j < lineBytes - 4; j++) //每列, 上面算的128列，现在只要102列，先取前96列
            for (int k = 0; k < 8; k++)
            {
                i = 1;
                row = 1;
                while (i <= 64)
                {
                    bin = 128;
                    num = 0;
                    while (bin != 0) //纵向每8个
                    {
                        num += (map[i][j][k] * bin);
                        bin /= 2;
                        i++;
                    }
                    map2[row++][col] = num;
                }
                col++;
            }
        int j = lineBytes - 4; //最后一个byte只取6个
        for (int k = 0; k < 6; k++)
        {
            i = 1;
            row = 1;
            while (i <= 64)
            {
                bin = 128;
                num = 0;
                while (bin != 0) //纵向每8个
                {
                    num += (map[i][j][k] * bin);
                    bin /= 2;
                    i++;
                }
                map2[row++][col] = num;
            }
            col++;
        }
        for (int i = 1; i <= row - 1; i++)
        {
            for (int j = 1; j <= col - 1; j++)
                fsout << "0x" << hex << map2[i][j] << ",";
            fsout << endl;
        }
        fsout.close();
    }
    fs.close();
    return 0;
}