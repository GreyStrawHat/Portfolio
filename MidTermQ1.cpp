/*
1.) Initialize necessary variables, total_students, student_name, total_test_scores, individual_test_scores, average_test_scores, and highest_test_score.
2.) Input student first namesand last initialsand store in an initialized variable.
3.) Use for loop to iterate for the number of students total.
3.) Input each students test scoresand store in appropriate variable.
//Determine average test score
4.) Use for loop to iterate through number of each student.
5.) Add individual_test_score values to current total_test_scores value
6.) When for loop ends, set value of average students to(total_test_scores / total_students)
//Determine and print the names of students who have below average test_scores.
7.) Use for loop to iterate through each student.
8.) If student_name < average_score then output student_name.
	//Determine highest score.
	9.) Use for loop to iterate through each student.
	10.) Ensure highest_test_score begins with the value 0.
	11.) If test_score > highest_test_score then highest_test_score = test_score.
	//Determine and print the names of students with the same score as highest_test_score.
	12.) Use for loop to iterate through each student.
	13.) If test_score = highest_test_score then output student_name.
*/
int total_student = (some_number);
string student_name = "First Name and Last Initial";
int total_test_score = 0;
int individual_test_scores;
int highest_test_score = 0;
double average_test_score = 0;

for (i = 0; i < total_students; i++)
	Output "Enter students test score";
Input "test score value" Store inside variable individual_test_score;
total_test_scores += individual_test_score;
if individual_test_score > highest_test_score then highest_test_score = test_score;

average_test_score = (total_test_scores / total_students);

for (i = 0; i < total_students; i++)
{
	Output "Enter students First name and last inital";
	Input "Student_Name" Store inside variable student_name using istreamvar.get() to preserve spaces;
	Output "Enter students test score";
	Input "test score value" Store inside variable individual_test_score;
	if individual_test_score < average_test_score then output Student_Name;
	if individual_test_score is equal to highest_test_score then output student_name;
}
return 0;










