//#include <iostream>
//#include <cstdlib>
//#include <algorithm>
//#include <thread>
//#include <chrono>
//using namespace std;
//
//// 定数
//const int LENGTH = 5; // 1 辺の長さ
//const int BOARD_SIZE = LENGTH * LENGTH; // 盤面のマス数
//
//int main()
//{
//	int result[BOARD_SIZE];
//	int size = sizeof(result) / sizeof(result[0]);
//	for (int i = 0; i < size; i++)
//	{
//		result[i] = i;
//	}
//
//	// シャッフル
//	for (int i = size - 1; i > 1; i--)
//	{
//		int index = rand() % (i - 1);
//		swap(result[i], result[index]);
//	}
//
//	for (int i = 0; i < BOARD_SIZE; i++)
//	{
//		for (int j = 0; j < LENGTH; j++)
//		{
//			cout << " ___";
//		}
//		cout << endl;
//		for (int j = 0; j < LENGTH; j++)
//		{
//			for (int k = 0; k < LENGTH + 1; k++)
//			{
//				if (k != 0)
//				{
//					cout << ' ';
//				}
//				cout << "| ";
//				if (k != LENGTH)
//				{
//					if (result[j * LENGTH + k] <= i)
//					{
//						cout << '*';
//					}
//					else
//					{
//						cout << ' ';
//					}
//				}
//			}
//			cout << endl;
//			for (int k = 0; k < LENGTH; k++)
//			{
//				cout << " ---";
//			}
//			cout << endl;
//		}
//		if (i != BOARD_SIZE - 1)
//		{
//			this_thread::sleep_for(chrono::seconds(1));
//			system("cls");
//		}
//	}
//
//}