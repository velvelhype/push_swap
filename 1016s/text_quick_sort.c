#include <stdio.h>

#define SIZE_OF_ARRAY(array)    (sizeof(array)/sizeof(array[0]))
#define SWAP(type,a,b) { type work = a; a = b; b = work; }

static void quick_sort(int* array, size_t size);
static void quick_sort_rec(int* array, int begin, int end);
static inline int select_pivot(const int* array, int begin, int end);
static void print_array(const int* array, size_t size);

int main(void)
{
    int array[] = {7, 2, 1, 3, 4, 8, 6, 5};

    print_array( array, SIZE_OF_ARRAY(array) );
    quick_sort( array, SIZE_OF_ARRAY(array) );
    print_array( array, SIZE_OF_ARRAY(array) );

    return 0;
}

/*
    クイックソート (昇順)
*/
void quick_sort(int* array, size_t size)
{
    // 配列全体を対象にする
    quick_sort_rec( array, 0, (int)(size - 1) );
}

/*
    クイックソート (再帰部分、昇順)
*/
void quick_sort_rec(int* array, int begin, int end)
{
    int pivot = select_pivot( array, begin, end );
    int i = begin;
    int j = end;

    while( 1 ){
        while( array[i] < pivot ){ ++i; }  // 基準値以上の値が見つかるまで右方向へ進めていく
        while( array[j] > pivot ){ --j; }  // 基準値以下の値が見つかるまで左方向へ進めていく

        if( i >= j )
        {
            print_array(array, 9);
            break; 
        }  // 左右から進めてきたiとjがぶつかったらループを終える

        // 基準値の位置よりも左側にあり、基準値よりも大きい値 (array[i]) と、
        // 基準値の位置よりも右側にあり、基準値よりも小さい値 (array[j]) の
        // 位置関係を交換する。
        SWAP( int, array[i], array[j] );

        // 次回に備えて、注目点をずらす
        i++;
        j--;
    }


    // 基準値の位置より左側に要素が２つ以上あれば、
    // その部分についてクイックソートを再帰させる
    if( i - begin >= 2 ){
        quick_sort_rec( array, begin, i - 1 );
    }

    // 基準値の位置より右側に要素が２つ以上あれば、
    // その部分についてクイックソートを再帰させる
    if( end - j >= 2 ){
        quick_sort_rec( array, j + 1, end );
    }
}

/*
    基準値を選ぶ
*/
inline int select_pivot(const int* array, int begin, int end)
{
    return array[(begin + end) / 2];  // 中央の要素を基準値とする
}

/*
    配列の要素を出力
*/
void print_array(const int* array, size_t size)
{
    for( size_t i = 0; i < size; ++i ){
        printf( "%d ", array[i] );
    }
    printf( "\n" );
}
