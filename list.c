#include <stdio.h>
#include <stdlib.h>

//リスト用構造体定義
struct LIST{
	LIST *next;
	int value;
};

//リストの先頭を定義
LIST list;

//関数のプロトタイプ宣言
void Add(int);
void Del(int);
void Display();
void Release();

int main(void)
{

	//最初は何もないので自分自身が最後でもある
	list.next=&list;
	
	
	char answer='5';
	int figure;

	puts("何をしますか？\n０.終了、１.追加、２.削除、３.表示\n");

	while(answer!='0'){

		scanf("%c",&answer);

		//入力バッファに残る\nをクリアする
		fflush(stdin);

		switch(answer){

			case '1':
				puts("追加する値を入力して下さい");
				scanf("%d",&figure);
				Add(figure);
				break;
			case '2':
				puts("削除する値を入力して下さい");
				scanf("%d",&figure);
				Del(figure);
				break;
			case '3':
				Display();
				break;
			default:
				puts("正しい値を入力して下さい");
				break;
		}
		//入力バッファに残る\nをクリアする
		fflush(stdin);
		puts("何をしますか？\n０.終了、１.追加、２.削除、３.表示\n");
	}

	//解放
	Release();

	return 0;

}

void Add(int temp){

	//新規確保用
	LIST *p;
	//現在の末尾のリストのポインタ；
	LIST *next;
	//末尾直前のポインタ
	LIST *prev;
	
	//新しいリストの領域を確保
	p=(LIST*)malloc(sizeof(LIST));

	//値を代入
	p->value=temp;
	//次の要素は先頭要素のポインタ
	p->next=&list;

	//最初は先頭が末尾直前のポインタになる
	prev=&list;

	//末尾のポインタまで移動
	for(next=list.next;next!=&list;next=next->next){
			prev=next;
	}

	//リストを連結する。
	prev->next=p;

	puts("追加しました");
	
}

void Del(int temp){

	//削除要素の直前の要素のポインタ
	LIST* prev;

	//最初は先頭要素の次のリストからチェックしてるので、
	//削除要素の直前の要素は先頭要素になる。
	prev=&list;

	//リストを末尾(先頭要素のポインタ)までループ
	for(LIST *p=list.next;p!=&list;p=p->next){

		//その値があれば
		if(p->value==temp){

			//削除要素の前のリストにつなげる
			//その前に次の要素が末尾ならつなげる必要ないのでチェック
			if(p->next!=&list){

				//削除直前の要素につなげる
				prev->next=p->next;

				//削除対象要素の解放
				free(p);

				return;
			}

			//末尾要素に先頭要素のポインタを保存
			prev->next=&list;

			//削除対象要素の解放
			free(p);

			puts("削除しました");

			return;			
		}

		prev=p;

	}
	puts("該当の値は見つかりませんでした");

}

void Display(){

	if(list.next==&list){
		puts("まだ何もありません");
		return;
	}

	//末尾まで全部表示
	for(LIST *p=list.next;p!=&list;p=p->next){

		printf("%d,",p->value);
	}

	puts("");

}

void Release(){

	//次のリストのポインタ
	LIST *next;
	//削除対象のポインタ
	LIST *del;

	next=list.next;

	//末尾までループ
	while(next!=&list){
		//削除対象のポインタを保存	
		del=next;
		//次のリストのポインタを取得しとく
		next=next->next;

		free(del);
	}
}
