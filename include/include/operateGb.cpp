//在此文件中定义与生成有关的各种函数
#include <iostream>
#include <vector>
#include <string>

#include "classofGb.hpp"
#include "example.cpp"

using namespace std;

//函数声明
void printGb(GenMatrix GB);//打印生成矩阵
void readGb(GenMatrix& GB);//读取输入的生成矩阵
void print_example();//打印案例
void initGB(GenMatrix& GB);//初始化生成矩阵类
void ErrorInput(vector<int>& t1, vector<vector<int>>& t2, GenMatrix& GB, int& enterflag, char& input);//输入错误重置参数


//函数定义
void initGB(GenMatrix& GB){//初始化生成矩阵类
	GB.n = -1;
	GB.m = -1;
	GB.k = -1;
	vector<vector<vector<int>>>().swap(GB.Gb);
}

void printGb(GenMatrix GB){//打印生成矩阵
	for(auto i:GB.Gb){
        for(auto j:i){
            for(auto k:j){
                cout << k;
            }
            cout << ' ';
  	    }
  	    cout << '\n';
    }
    cout  << "dimensionality of inputs(n): " << GB.n << '\n';
    cout << "memory length(m): " << GB.m << '\n';
    cout << "dimensionality of outputs(k): " << GB.k << '\n';  
}

void ErrorInput(vector<int>& t1, vector<vector<int>>& t2, GenMatrix& GB, int& enterflag, char& input){//输入错误重置参数
	//将当前行已输入的数据读完
	while(input != '\n'){
		input = cin.get();
	}
	//重置参数
	cout << "input error!\nplease re-input the generating-matrix(or enter to load example):\n";
	vector<int>().swap(t1);
	vector<vector<int>>().swap(t2);
	initGB(GB);
	enterflag = 0;
}

void readGb(GenMatrix& GB){//读取输入的生成矩阵
	cout << "\ninput the generating-matrix(or enter to load example):\n";
	char input;//输入
	vector<int> t1;//暂存数据
	vector<vector<int>> t2;//同上
	int enterflag = 0;//记录按下回车的次数
	while(true){//读取输入
		input = cin.get();
		if(input == '\n' || input == ' '){//输入回车或空格则读取之前存储的t1
			if(t1.size() > 0){
				if(GB.k < 0){
					GB.k = t1.size();
				}
				else if(t1.size() != static_cast<unsigned long int>(GB.k)){
					ErrorInput(t1,t2,GB,enterflag,input);
					continue;
				}
				t2.push_back(t1);
				vector<int>().swap(t1);
			}
			if(input == '\n'){//输入回车则进一步读取存储的t2
				if(t2.size() == 0 && enterflag == 0){
					string a;//无用参数
					readexample(a, GB);
					break;
				}
				else if(t2.size() == 0 && enterflag == 1){
					GB.n = GB.Gb.size();
					break;
				}
				else if(GB.m < 0){
					GB.m = t2.size()-1;
				}
				else if(t2.size() != static_cast<unsigned long int>(GB.m+1)){
					ErrorInput(t1,t2,GB,enterflag,input);
					continue;
				}
				GB.Gb.push_back(t2);
				vector<vector<int>>().swap(t2);
				enterflag = 1;
			}
		}
		else if(input == '1' || input == '0'){
			t1.push_back(input-48);
			if(t1.size() > static_cast<unsigned long int>(GB.k)){
				ErrorInput(t1,t2,GB,enterflag,input);
			}
			enterflag = 0;
		}
		else{
			ErrorInput(t1,t2,GB,enterflag,input);
		}
	}
	cout << "\nDetected generating-matrix(Gb):\n";
	printGb(GB);//调用打印生成矩阵函数
}

void print_example(){//打印案例
    string ex_structure;
    GenMatrix ex_GB;
    readexample(ex_structure, ex_GB);//调用读取示例的函数
    cout << "example of structure:\n";
    cout << ex_structure << endl;
    cout << "its corresponding generating-matrix(Gb):\n";
    printGb(ex_GB);//调用打印生成矩阵函数
}
