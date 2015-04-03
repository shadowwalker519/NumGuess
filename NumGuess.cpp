#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	char choice;
	int num_1, num_2, num_3, guess_1, guess_2, guess_3, i, j, A, B, win_times = 0, times = 0, lose_times = 0;
	/* win_times: how many times the user wins, times: how many times the user plays, lose_times: how many times the user loses
	   A: how many numbers guessed have the same value and location as the random numbers generated 
           B: how many numbers guessed have the same value but different location as the random numbers generated 
           num_1, num_2, num_3: numbers randomly generated, guess_1, guess_2, guess_3:numbers user guessed*/
			
	srand(time(NULL));		
	
	cout << "Start the game(Y/N)?" << endl;
	cin >> choice;
	cin.sync();
	while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
	{
		cout << "Please make your choice within 'y' or 'Y' or 'n' or 'N'." << endl;
		cin >> choice;
		cin.sync();
	}
	//Ignore strange inputs
	
	while (choice == 'Y' || choice == 'y'){
		j = 1;
		num_1 = rand() % 10;
		do {
			num_2 = rand() % 10;
		}while(num_2 == num_1);                   // Make sure random number 2 is not equal to number 1
		do {
			num_3 = rand() % 10;
		}while(num_3 == num_2 || num_3 == num_1); // Make sure random number 3 is not equal to number 1 and number 2
		while (j <= 7){
			++j;
			cout << "Please guess the numbers:" << endl;
			cin >> guess_1 >> guess_2 >> guess_3;
			A = ((num_1 == guess_1) + (num_2 == guess_2) + (num_3 == guess_3));
			B = ((num_1 == guess_2) + (num_1 == guess_3) + (num_2 == guess_1) + (num_2 == guess_3) + (num_3 == guess_1) + (num_3 == guess_2));	
			if (A == 3){	
				cout << "Congratulations! You have won the game." << endl;
				++ win_times;
				break;
			}
			else cout << A << 'A' << B << 'B' << '\n';
		}
		if ((j == 8) && (A != 3)) cout << "Sorry, you haven't got the right answer. The key is " << num_1 <<' '<< num_2 <<' '<< num_3 << endl;
		++ times;
		cout << "Continue(Y/N)?" << endl;         // User can play many times they want
		cin >> choice;
		cin.sync();
		while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
		{
			cout << "Please make your choice within 'y' or 'Y' or 'n' or 'N'." << endl;
			cin >> choice;
			cin.sync();
		}
	}
	lose_times = times - win_times;
	
	cout << "You have played " << times << " round(s), winning " << win_times << " round(s), losing " << lose_times << " round(s)." << endl;
	
	return 0;
}
