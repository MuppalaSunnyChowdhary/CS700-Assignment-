#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

///The code fragment parsingASCII helps us in parcing the string to integers using the 
///ascii values by iterating through the string and subracting the value 48 from the ascii 
///value as we only need the integers which is nothing but, In ASCII, '0' == 48, '1' == 49, and so on. 
///Thus, '0' - 48 == 0, '1' - 48 == 1, and so on. That is, subtracting by 48 translates the char values 
///'0'..'9' to the int values 0..9.

int parsingASCII(string s)
{

	int num = 0;/// Initialize a variable
	int n = s.length(); /// Iterate till length of the string
	for (int i = 0; i < n; i++) /// Subtract 48 from the current digit
		num = num * 10 + (int(s[i]) - 48);
	return num;
}

int main()
{

	fstream newfile, myfile;
	string tp = "", str = "", examscores = "", marks = "";
	int total = 0, markN = 0, nos = 0, noofexams, p, i, no = 1;
	string studentname = "";
	newfile.open("grades.txt", ios::in); ///open a file to perform read operation using file object
	myfile.open("output.txt", ios::out); /// creating output file
	if (newfile.is_open()) ///checking whether the file can be opened
	{


		while (getline(newfile, tp))  ///read data from file object and put it into string.
		{
			cout << "STUDENT-" << no << endl;
			myfile << "STUDENT-" << no << endl;
			for (i = 0; i < tp.length(); i++)
			{
				if (isalpha(tp.at(i)) || tp.at(i) == ' ')
				{
					studentname += tp.at(i);
				}
				else
				{
					str = tp.substr(i);/// string of no of subject and marks
					break;
				}
			}
			nos = str.find(" "); /// first occurrence of space to find number of subjects only
			string findex = str.substr(0, nos);
			noofexams = parsingASCII(findex); /// number of subjects
			examscores = str.substr(nos + 1); /// only string of scores

			for (p = 0; p < examscores.length(); p++)
			{
				if ((examscores.at(p)) != ' ')
				{
					marks += examscores.at(p);	/// creating string formatted marks
				}
				else
				{
					markN = parsingASCII(marks);	/// converting string marks into numeric marks
					total = total + markN;
					marks = "";
				}
			}

			string examegrade = "";
			double Average = ((float)total / (noofexams * 100.0)) * 100.0;
			///here we have used the nested if statments inorder to calculate the grade according to the 
			///problem statement which goes in the similar fashion
			if (Average >= 95.0 && Average <= 100.0)
			{
				examegrade = "A";
			}
			else if (Average >= 91.67 && Average < 95.0)
			{
				examegrade = "A-";
			}
			else if (Average >= 88.3 && Average < 91.67)
			{
				examegrade = "B+";
			}
			else if (Average >= 85 && Average < 88.3)
			{
				examegrade = "B";
			}
			else if (Average >= 81.67 && Average < 85.0)
			{
				examegrade = "B-";
			}
			else if (Average >= 78.33 && Average < 81.67)
			{
				examegrade = "C+";
			}
			else if (Average >= 75.0 && Average < 78.33)
			{
				examegrade = "C";
			}
			else if (Average >= 71.67 && Average < 75.0)
			{
				examegrade = "C-";
			}
			else if (Average >= 68.33 && Average < 71.67)
			{
				examegrade = "D+";
			}
			else if (Average >= 65 && Average < 68.33)
			{
				examegrade = "D";
			}
			else if (Average >= 61.67 && Average < 65.0)
			{
				examegrade = "D-";
			}
			else
			{
				examegrade = "F";
			}

			cout << "Name of the student---->" << studentname << endl;
			cout << "No of exams---->" << noofexams << endl;
			cout << "Scores---->" << examscores << endl;
			cout << "Total marks obtained----->" << total << endl;
			cout << "Average exam score----->" << setprecision(4) << Average << "%" << endl;
			cout << "Letter grade------>" << examegrade << endl;
			cout << "--------------------------------------------------------------------------" << endl;

			myfile << "Name of the student---->" << studentname << endl;
			myfile << "No of subjects---->" << noofexams << endl;
			myfile << "Scores of subjects---->" << examscores << endl;
			myfile << "Total marks obtained----->" << total << endl;
			myfile << "Average exam score----->" << setprecision(4) << Average << "%" << endl;
			myfile << "Letter grade------>" << examegrade << endl;
			myfile << "--------------------------------------------------------------------------" << endl;
			marks = "";
			total = 0;
			studentname = "";
			markN = 0;
			no++;
		}

	}
	else
	{
		cout << "File does not exist";
	}


	newfile.close();
	myfile.close();
	return 0;
}
