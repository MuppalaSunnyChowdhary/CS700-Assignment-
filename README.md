# CS700-Assignment-1

The coding for the first section of the assignment is https://github.com/sunmupp/CS700-Assignment-1-main/blob/main/Assign1_Q1.cpp

The textfile used as the input is https://github.com/sunmupp/CS700-Assignment-1-main/blob/main/grades.txt

The code fragment parsingASCII helps us in parcing the string to integers using the ascii values by iterating through the string and subracting the value 48 from the ascii value as we only need the integers which is nothing but, In ASCII, '0' == 48, '1' == 49, and so on. Thus, '0' - 48 == 0, '1' - 48 == 1, and so on. That is, subtracting by 48 translates the char values '0'..'9' to the int values 0..9.

{

	int num = 0;// Initialize a variable
	int n = s.length(); // Iterate till length of the string
	for (int i = 0; i < n; i++) // Subtract 48 from the current digit
		num = num * 10 + (int(s[i]) - 48);
	return num;
}

In the main function we have used the nested if statments inorder to calculate the grade according to the problem statement which goes in the similar fashion

{

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
	
}

the output is displayed in the compiler and the same is been stored in a separate file: https://github.com/sunmupp/CS700-Assignment-1-main/blob/main/output.txt

and the output screenshot: https://github.com/sunmupp/CS700-Assignment-1-main/blob/main/Screenshot%202022-09-27%20at%2010.39.52%20AM.png

<!-- blank line -->
----
<!-- blank line -->

The coding for the first section of the assignment is https://github.com/sunmupp/CS700-Assignment-1-main/blob/main/Assign1_Q2.cpp

The textfile used as the input is https://github.com/sunmupp/CS700-Assignment-1-main/blob/main/grades_Section2.txt

The code fragment parsingASCII helps us in parcing the string to integers using the ascii values by iterating through the string and subracting the value 48 from the ascii value as we only need the integers which is nothing but, In ASCII, '0' == 48, '1' == 49, and so on. Thus, '0' - 48 == 0, '1' - 48 == 1, and so on. That is, subtracting by 48 translates the char values '0'..'9' to the int values 0..9.

{

	int num = 0;// Initialize a variable
	int n = s.length(); // Iterate till length of the string
	for (int i = 0; i < n; i++) // Subtract 48 from the current digit
		num = num * 10 + (int(s[i]) - 48);
	return num;
}

In the output function we have used the nested if statments inorder to calculate the grade according to the problem statement which goes in the similar fashion

{

			if (s[k][m] < (avg[m] - 5))
				g = "no grade";
			else if ((s[k][m] >= (avg[m] - 5)) && s[k][m] <= (avg[m] + 5))
				g = "C";
			else if (s[k][m] > (avg[m] + 5) && s[k][m] <= (avg[m] + 14))
				g = "B(D)";
			else
				g = "A(F)";
}

the output is displayed in the compiler and the same is been stored in a separate file: https://github.com/sunmupp/CS700-Assignment-1-main/blob/main/output_Section2.txt

and the output screenshot: https://github.com/sunmupp/CS700-Assignment-1-main/blob/main/Screenshot%202022-09-27%20at%2010.42.18%20AM.png
# CS700-Assignment-1-main
