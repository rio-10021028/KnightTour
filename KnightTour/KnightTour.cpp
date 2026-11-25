#include <iostream>
#include <cstring>
using namespace std;

// 定数
const int LENGTH = 5; // 1 辺の長さ
const int BOARD_SIZE = LENGTH * LENGTH; // 盤面のマス数

bool knightTour(bool* pboard, int record, int field, int* pcurrentCount, int* pmaxCount)
{
	// 現在地のindex を record と field から求める
	int currentIndex = LENGTH * (record - 1) + (field - 1);

	// 現在地の処理
	if (1 <= record && record <= LENGTH && 1 <= field && field <= LENGTH // ボードからはみ出てないか確認 +
		&& !pboard[currentIndex])										 // 未踏の地か確認
	{
		// ボードの現在地をtrue にする
		pboard[currentIndex] = true;
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
	// このマスを false に戻して、 currentCount も -1 する
	(*pcurrentCount)--;
	pboard[currentIndex] = false;
	return false;
}

int main()
{
	bool board[BOARD_SIZE];
	memset(board, false, sizeof(board));	// 0 で埋める

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
	}
	else
	{
		cout << "廻れなかったらしいよ" << endl
			<< "currentCount -> " << currentCount << endl
			<< "maxCount -> " << maxCount << endl;
	}
}