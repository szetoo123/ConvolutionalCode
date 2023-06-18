#ifndef _GEN_MATRIX_H_
#define _GEN_MATRIX_H_

#include <vector>
using namespace std;

class GenMatrix{
    public:
        int n;//输入信号的维数
        int m;//卷积码记忆长度
        int k;//卷积码输出维数
        vector<vector<vector<int>>> Gb;//定义生成矩阵
};

#endif