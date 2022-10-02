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

int parsingASCII(string fileinput)
{

	int marks = 0;
	int n = fileinput.length();
	for (int i = 0; i < n; i++) /// Subtract 48 from the current digit 
		marks = marks * 10 + (int(fileinput[i]) - 48);
	return marks;
}

int output(int s[100][100], int noofStudents, int noofExams, int avg[100], string* name)
{
	string g = "";
	int m = 0, sum = 0, k = 0;
	fstream myfile;
	myfile.open("output_Section2.txt", ios::out); /// creating output file

	for (k = 0; k < noofStudents; k++) ///calculation avarage score for each exam
	{
		cout << "student no---->" << (k + 1) << endl;
		myfile << "student no---->" << (k + 1) << endl;
		cout << "student name---->" << name[k] << endl;
		myfile << "student name---->" << name[k] << endl;
		for (m = 0; m < noofExams; m++)	///calculating grade based on criteria
		{

			///here we have used the nested if statments inorder to calculate the grade according to the 
			///problem statement which goes in the similar fashion

			if (s[k][m] < (avg[m] - 5))
				g = "no grade";
			else if ((s[k][m] >= (avg[m] - 5)) && s[k][m] <= (avg[m] + 5))
				g = "C";
			else if (s[k][m] > (avg[m] + 5) && s[k][m] <= (avg[m] + 14))
				g = "B(D)";
			else
				g = "A(F)";


			cout << "subject: " << (m + 1) << "\t average score:  " << avg[m] << "\t Student's score:  " << s[k][m] << "\t Grade--------->" << g << endl;
			myfile << "subject: " << (m + 1) << "   average score:  " << avg[m] << "   Student's score:  " << s[k][m] << "  Grade--------->" << g << endl;
		}
		cout << "------------------------------------------------------------------------------------------------------" << endl;
		myfile << "---------------------------------------------------------------------------------------------------------------" << endl;
		sum = 0;
	}
	myfile.close();
	return 0;
}

int main()
{

	fstream newfile1;
	string str = "", name = "", Smarks = "", grade = "";
	int i = 0, ASCIImark = 0, c = 0, r = 0, p = 0, k = 0, j = 0, row = 0, col = 0, x = 0, sum = 0, a = 0;
	int score[100][100], aver[100];
	string sname[100];
	newfile1.open("grades_Section2.txt", ios::in); ///open a file to perform read operation using file object
	if (newfile1.is_open()) ///checking whether the file is opened
	{

		int noofStudents = 0;
    	int noofExams= 0;
    	newfile1 >> noofStudents >> noofExams;
		cout << "no of row and col"<<noofStudents << "," << noofExams<<endl;

		while (getline(newfile1, str))  ///read data from file object and put it into string.
		{
			str += " ";
			for (i = 0; i < str.length(); i++)
			{
				if (isalpha(str.at(i)) || str.at(i) == ' ')
				{
					name += str.at(i);
				}
				else
				{
					sname[x++] = name; /// inserting each student's name in sname array
					name = "";
					break;
				}
			}

			for (p = i; p < str.length(); p++)
			{

				if ((str.at(p)) != ' ')
				{
					Smarks += str.at(p);
				}
				else
				{
					ASCIImark = parsingASCII(Smarks);	/// converting string marks into numeric marks
					if (c < noofExams)
					{
						score[r][c] = ASCIImark;/// inserting marks in the score array
						c++;
					}
					Smarks = "";
				}

			}
			r++;
			c = 0;

		}
		for (a = 0; a < noofExams; a++) /// calculating average exam score subject wise
		{
			for (j = 0; j < noofStudents; j++)
			{
				sum = sum + score[j][a];
			}
			aver[a] = (sum / noofStudents);
			sum = 0;

		}
		output(score, noofStudents, noofExams, aver, sname); /// calling Grade function

	}
	else
		cout << "Error opening file" << endl;

	newfile1.close();
	return 0;
}