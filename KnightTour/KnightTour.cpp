#include <iostream>
#include <cstring>
#include <thread>
#include <chrono>
using namespace std;

// 定数
const int LENGTH = 5; // 1 辺の長さ
const int BOARD_SIZE = LENGTH * LENGTH; // 盤面のマス数

// 配列の中で一番大きい数値を返す関数
int arrMax(int* pboard)
{
	int currentMax = -1;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		currentMax = max(currentMax, pboard[i]);
	}

	return currentMax;
}

bool knightTour(int* pboard, int record, int field, int* pcurrentCount, int* pmaxCount)
{
	// 現在地のindex を record と field から求める
	int currentIndex = LENGTH * (record - 1) + (field - 1);

	// 現在地の処理
	if (1 <= record && record <= LENGTH && 1 <= field && field <= LENGTH // ボードからはみ出てないか確認 +
		&& pboard[currentIndex] == -1)										 // 未踏の地か確認
	{
		// ボードの現在地を到達した順番 にする
		if (arrMax(pboard) == -1)
		{
			pboard[currentIndex] = 0;
		}
		else
		{
			pboard[currentIndex] = arrMax(pboard) + 1;
		}
		(*pcurrentCount)++;
		if (*pcurrentCount > *pmaxCount)
		{
			*pmaxCount = *pcurrentCount;
		}
	}
	else
	{
		return false;
	}

	// 成功チェック(ボードが全部 true だったら return true)
	if (*pcurrentCount == BOARD_SIZE)
	{
		return true;
	}

	// 次の場所へ
	int nextRecord;
	int nextField;

	// 移動先
	const int nextPos[8][2] =
	{
		{-2, -1},
		{-2, 1},
		{-1, -2},
		{-1, 2},
		{1, -2},
		{1, 2},
		{2, -1},
		{2, 1},
	};

	for (int i = 0; i < 8; i++)
	{
		nextRecord = record + nextPos[i][0];
		nextField = field + nextPos[i][1];
		if (knightTour(pboard, nextRecord, nextField, pcurrentCount, pmaxCount))
		{
			return true; // 移動先でtrue で返ってきたら、上にtrue で返す
		}
	}

	// すべての移動先を試して、全部 false なら、
	// このマスを -1 に戻して、 currentCount も -1 する
	(*pcurrentCount)--;
	pboard[currentIndex] = -1;
	return false;
}

void showRoute(int* pboard)
{
	cout << "ルートを表示します" << endl;
	this_thread::sleep_for(chrono::seconds(3));
	system("cls");

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < LENGTH; j++)
		{
			cout << " ___";
		}
		cout << endl;
		for (int j = 0; j < LENGTH; j++)
		{
			for (int k = 0; k < LENGTH + 1; k++)
			{
				if (k != 0)
				{
					cout << ' ';
				}
				cout << "| ";
				if (k != LENGTH)
				{
					if (pboard[j * LENGTH + k] <= i)
					{
						cout << '*';
					}
					else
					{
						cout << ' ';
					}
				}
			}
			cout << endl;
			for (int k = 0; k < LENGTH; k++)
			{
				cout << " ---";
			}
			cout << endl;
		}
		if (i != BOARD_SIZE - 1)
		{
			this_thread::sleep_for(chrono::seconds(1));
			system("cls");
		}
	}
}

int main()
{
	int board[BOARD_SIZE];
	fill_n(board, sizeof(board) / sizeof(board[0]), -1);	// -1 で埋める

	int record = 0;
	int field = 0;

	int currentCount = 0; // 現在の踏破済みマス数
	int maxCount = 0; // 最高到達マス数

	//// field を表示
	//for (int i = 0; i < 8; i++)
	//{
	//	for (int j = 0; j < 8; j++)
	//	{
	//		cout << board[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	cout << "初期位置は、" << endl
		<< "何行目？ > " << flush;
	cin >> record;
	cout << "何列目？ > " << flush;
	cin >> field;

	if (knightTour(board, record, field, &currentCount, &maxCount))
	{
		cout << "廻れたらしいよ" << endl
			<< "currentCount -> " << currentCount << endl
			<< "maxCount -> " << maxCount << endl;

		//for (int i = 0; i < BOARD_SIZE; i++)
		//{
		//	cout << board[i] << ' ';
		//}

		showRoute(board);

		cout << "やったね" << endl;
	}
	else
	{
		cout << "廻れなかったらしいよ" << endl
			<< "currentCount -> " << currentCount << endl
			<< "maxCount -> " << maxCount << endl;
	}
}