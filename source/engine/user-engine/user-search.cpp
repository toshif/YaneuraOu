﻿#include "../../types.h"
#include "../../extra/all.h"

#if defined(USER_ENGINE)

using namespace std;

// USI拡張コマンド"user"が送られてくるとこの関数が呼び出される。実験に使ってください。
void user_test(Position& pos_, std::istringstream& is)
{
  cout << "toshi debug test." << endl;
}

// USIに追加オプションを設定したいときは、この関数を定義すること。
// USI::init()のなかからコールバックされる。
void USI::extra_option(USI::OptionsMap & o)
{
}

// 起動時に呼び出される。時間のかからない探索関係の初期化処理はここに書くこと。
void Search::init()
{
}

// isreadyコマンドの応答中に呼び出される。時間のかかる処理はここに書くこと。
void  Search::clear()
{
}

// 探索開始時に呼び出される。
// この関数内で初期化を終わらせ、slaveスレッドを起動してThread::search()を呼び出す。
// そのあとslaveスレッドを終了させ、ベストな指し手を返すこと。
void MainThread::search()
{
  MoveList<LEGAL> moves(rootPos);
  if (moves.size() == 0){
    sync_cout << MOVE_RESIGN << sync_endl;
    return;
  }

  Move bestMove = moves.at(rand() % moves.size()).move;
  sync_cout << "bestmove " << bestMove << sync_endl;

  // 例)
  //  for (auto th : Threads.slaves) th->start_searching();
  //  Thread::search();
  //  for (auto th : Threads.slaves) th->wait_for_search_finished();
}

// 探索本体。並列化している場合、ここがslaveのエントリーポイント。
void Thread::search()
{
}

#endif // USER_ENGINE
