#include <stdio.h>
#include <stdlib.h>

//リスト用構造体定義
typedef struct LIST{
	struct LIST *next;
	struct LIST *prev;
	int value;
} LIST;

int main()
{
	//struct LIST *hell;
	LIST *hell = malloc (sizeof(LIST));
	hell->value = 19;
	printf("%d\n", hell->value);
}

// //リストの先頭を定義
// struct LIST;

// //関数のプロトタイプ宣言
// void Add(int);
// void Del(int);
// void Display();
// void Release();

// int main(void)
// {

// 	//最初は何もないので自分自身が最後でもある
// 	list.next = &struct LIST;
// 	//循環リストだと前の要素も自分なので自分のポインタをセット
// 	struct LIST.prev=&struct LIST;
	
	
// 	char answer='5';
// 	int figure;

// 	puts("何をしますか？\n０.終了、１.追加、２.削除、３.表示\n");

// 	while(answer!='0'){

// 		scanf("%c",&answer);

// 		//入力バッファに残る\nをクリアする
// 		fflush(stdin);

// 		switch(answer){

// 			case '1':
// 				puts("追加する値を入力して下さい");
// 				scanf("%d",&figure);
// 				Add(figure);
// 				break;
// 			case '2':
// 				puts("削除する値を入力して下さい");
// 				scanf("%d",&figure);
// 				Del(figure);
// 				break;
// 			case '3':
// 				Display();
// 				break;
// 			default:
// 				puts("正しい値を入力して下さい");
// 				break;
// 		}
// 		//入力バッファに残る\nをクリアする
// 		fflush(stdin);
// 		puts("何をしますか？\n０.終了、１.追加、２.削除、３.表示\n");
// 	}

// 	//解放
// 	Release();

// 	return 0;

// }

// void Add(int temp){

// 	//新規確保用
// 	struct LIST *p;
// 	//現在の末尾のリストのポインタ；
// 	struct LIST *next;
// 	//末尾直前のポインタ
// 	struct LIST *prev;
	
// 	//新しいリストの領域を確保
// 	p=(struct LIST*)malloc(sizeof(struct LIST));

// 	//値を代入
// 	p->value=temp;
// 	//次の要素は先頭要素のポインタ
// 	p->next=&struct LIST;

// 	//最初は先頭が末尾直前のポインタになる
// 	prev=&struct LIST;

// 	//末尾のポインタまで移動
// 	for(next=struct LIST.next;next!=&struct LIST;next=next->next){
// 			prev=next;
// 	}

// 	//リストを連結する。
// 	prev->next=p;
// 	//新しく確保した要素のprevメンバにも前の要素のポインタを入れる
// 	p->prev=prev;

// 	puts("追加しました");
	
// }

// void Del(int temp){

// 	//削除要素の直前の要素のポインタ
// 	struct LIST* prev;

// 	//最初は先頭要素の次のリストからチェックしてるので、
// 	//削除要素の直前の要素は先頭要素になる。
// 	prev=&struct LIST;

// 	//リストを末尾(先頭要素のポインタ)までループ
// 	for(struct LIST *p=struct LIST.next;p!=&struct LIST;p=p->next){

// 		//その値があれば
// 		if(p->value==temp){

// 			//削除要素の前のリストにつなげる
// 			//その前に次の要素が末尾ならつなげる必要ないのでチェック
// 			if(p->next!=&struct LIST){

// 				//削除直前の要素につなげる
// 				prev->next=p->next;
// 				//削除した次の要素のprevに、削除直前の要素のポインタをセット
// 				p->next->prev=prev;

// 				//削除対象要素の解放
// 				free(p);

// 				return;
// 			}

// 			//末尾要素に先頭要素のポインタを保存
// 			prev->next=&struct LIST;
// 			//先頭要素のprevに末尾要素のポインタを第ニュ
// 			struct LIST.prev=prev;

// 			//削除対象要素の解放
// 			free(p);

// 			puts("削除しました");

// 			return;			
// 		}

// 		prev=p;

// 	}
// 	puts("該当の値は見つかりませんでした");

// }

// void Display(){

// 	if(struct LIST.next==&struct LIST){
// 		puts("まだ何もありません");
// 		return;
// 	}

// 	//NULLになるまで全部表示
// 	for(struct LIST *p=struct LIST.next;p!=&struct LIST;p=p->next){

// 		printf("%d,",p->value);
// 	}

// 	puts("");

// }

// void Release(){

// 	//次のリストのポインタ
// 	struct LIST *next;
// 	//削除対象のポインタ
// 	struct LIST *del;

// 	next=struct LIST.next;

// 	//NULLになるまでループ
// 	while(next!=&struct LIST){
// 		//削除対象のポインタを保存	
// 		del=next;
// 		//次のリストのポインタを取得しとく
// 		next=next->next;

// 		free(del);
// 	}
// }