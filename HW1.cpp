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
	
	cout << "需要玩游戏吗（Y/N）？";
	cin >> choice;
	
	while (choice == 'Y'){
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
			cout << "请输入你猜测的数字:";
			cin >> guess_1 >> guess_2 >> guess_3;
			A = ((num_1 == guess_1) + (num_2 == guess_2) + (num_3 == guess_3));
			B = ((num_1 == guess_2) + (num_1 == guess_3) + (num_2 == guess_1) + (num_2 == guess_3) + (num_3 == guess_1) + (num_3 == guess_2));	
			if (A == 3){	
				cout << "恭喜，你猜对了";
				++ win_times;
				break;
			}
			else cout << A << 'A' << B << 'B' << '\n';
		}
		if ((j == 8) && (A != 3)) cout << "很遗憾，你没有在规定次数内猜对。答案是 " << num_1 <<' '<< num_2 <<' '<< num_3;
		++ times;
		cout << "需要玩游戏吗（Y/N）？";          // User can play many times they want
		cin >> choice;		
	}
	lose_times = times - win_times;
	
	cout << "你一共玩了" << times << "局，赢了" << win_times << "局，输了" << lose_times << "局";
	
	return 0;
}
