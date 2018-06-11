#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

int main()
{
	int num=0,bnum=0,gnum=0;
	double sum = 0;
	double bsum = 0;
	double gsum = 0;
	struct Stu
	{
		string name;
		string sex;
		string mark;
		int given;
		double grade;
		
	}stu[100];

	ifstream in;
	in.open("score.csv");
	if (!in)
	{
		cerr << "打开文件失败！" << endl;
	}
	string str;
	getline(in, str);
	while (!in.eof())
	{
		
		getline(in, stu[num].name,',');
		in.get();
		getline(in, stu[num].sex, ',');
		in.get();
		getline(in, stu[num].mark);
		stringstream s;
		s << stu[num].mark;
		s >> stu[num].grade;
		
		stu[num].given = stu[num].name[stu[num].name.size()-1];
	
		if (stu[num].sex == "Female")
		{
			gnum++;
			gsum += stu[num].grade;
		}
		if (stu[num].sex == "Male")
		{
			bnum++;
			bsum += stu[num].grade;
		}
		
		sum += stu[num].grade;
		num++;
		
	}
	num-=1;//
	for (int  i = 0; i < num; i++)
	{

		for (int  j = i+1; j < num; j++)
		{
			if (stu[i].grade < stu[j].grade)
			{
				Stu t = stu[j];
				stu[j] = stu[i];
				stu[i] = t;
			}
			if (stu[i].given > stu[j].given&&stu[i].grade==stu[j].grade)
			{
				Stu t = stu[j];
				stu[j] = stu[i];
				stu[i] = t;
			}
		}

	}
	for(int i=0;i<num;i++)
	cout <<stu[i].name<<" "<<stu[i].sex<<" "<< stu[i].grade << endl;
	cout << "the average of the class is " << sum / num<<endl;
	cout << "the average of the boys is " << bsum / bnum << endl;
	cout << "the average of the girls is " << gsum / gnum << endl;

	
}
