#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// コマンド
enum Cmd_tag {
    CMD_ADD,
    CMD_DELETE,
    CMD_SEARCH,
    CMD_CLEAR,
    CMD_PRINT,
    CMD_EXIT,

    CMD_NUM
};

// コマンド文字列の種類
enum CmdStr_tag {
    CMD_STR_SHORT,
    CMD_STR_LONG,

    CMD_STR_NUM
};

// コマンドの戻り値
enum CmdRetValue_tag {
    CMD_RET_VALUE_CONTINUE,
    CMD_RET_VALUE_EXIT,
};


// コマンド文字列
static const char* const CMD_STR[CMD_NUM][CMD_STR_NUM] = {
    { "a", "add" },
    { "d", "delete" },
    { "s", "search" },
    { "c", "clear" },
    { "p", "print" },
    { "e", "exit" }
};

static void init_head(void);
static void print_explain(void);
static void print_blank_lines(void);
static enum CmdRetValue_tag get_cmd(void);
static enum CmdRetValue_tag cmd_add(void);
static enum CmdRetValue_tag cmd_delete(void);
static enum CmdRetValue_tag cmd_search(void);
static enum CmdRetValue_tag cmd_clear(void);
static enum CmdRetValue_tag cmd_print(void);
static enum CmdRetValue_tag cmd_exit(void);
static void add_elem(int value);
static int delete_elem(int value);
static void clear_list(void);
static void print_list(void);
static struct LinkedList_tag* search_tail(void);
static struct LinkedList_tag* search_elem(int value);
static void get_line(char* buf, size_t size);

// コマンド実行関数
typedef enum CmdRetValue_tag (*cmd_func)(void);
static const cmd_func CMD_FUNC[CMD_NUM] = {
    cmd_add,
    cmd_delete,
    cmd_search,
    cmd_clear,
    cmd_print,
    cmd_exit
};

// 連結リスト型
struct LinkedList_tag {
    int                         value;
    struct LinkedList_tag*      next;
};

static struct LinkedList_tag gHead;  // 先頭の要素



int main(void)
{
    init_head();

    while( 1 ){
        print_explain();

        if( get_cmd() == CMD_RET_VALUE_EXIT ){
            break;
        }

        print_blank_lines();
    }

    return 0;
}

/* 
    先頭要素を初期化
*/
void init_head(void)
{
    gHead.value = 0;
    gHead.next = NULL;
}

/*
    説明文を出力
*/
void print_explain(void)
{
    puts( "コマンドを入力してください。" );
    printf( "　連結リストに要素を追加する: %s (%s)\n", CMD_STR[CMD_ADD][CMD_STR_SHORT], CMD_STR[CMD_ADD][CMD_STR_LONG] );
    printf( "　連結リストから要素を削除する: %s (%s)\n", CMD_STR[CMD_DELETE][CMD_STR_SHORT], CMD_STR[CMD_DELETE][CMD_STR_LONG] );
    printf( "　連結リストから要素を探す: %s (%s)\n", CMD_STR[CMD_SEARCH][CMD_STR_SHORT], CMD_STR[CMD_SEARCH][CMD_STR_LONG] );
    printf( "　連結リストを空にする: %s (%s)\n", CMD_STR[CMD_CLEAR][CMD_STR_SHORT], CMD_STR[CMD_CLEAR][CMD_STR_LONG] );
    printf( "　連結リストの中身を出力する: %s (%s)\n", CMD_STR[CMD_PRINT][CMD_STR_SHORT], CMD_STR[CMD_PRINT][CMD_STR_LONG] );
    printf( "　終了する: %s(%s)\n", CMD_STR[CMD_EXIT][CMD_STR_SHORT], CMD_STR[CMD_EXIT][CMD_STR_LONG] );
    puts( "" );
}

/*
    空白行を出力
*/
void print_blank_lines(void)
{
    puts( "" );
    puts( "" );
}

/*
    コマンドを受け付ける
*/
enum CmdRetValue_tag get_cmd(void)
{
    char buf[20];
    get_line( buf, sizeof(buf) );

    enum Cmd_tag cmd = CMD_NUM;
    for( int i = 0; i < CMD_NUM; ++i ){
        if( strcmp( buf, CMD_STR[i][CMD_STR_SHORT] ) == 0
         || strcmp( buf, CMD_STR[i][CMD_STR_LONG] ) == 0
        ){
            cmd = i;
            break;
        }
    }

    if( 0 <= cmd && cmd < CMD_NUM ){
        return CMD_FUNC[cmd]();
    }
    else{
        puts( "そのコマンドは存在しません。" );
    }

    return CMD_RET_VALUE_CONTINUE;
}

/*
    addコマンドの実行
*/
enum CmdRetValue_tag cmd_add(void)
{
    char buf[40];
    int value;

    puts( "追加する数値データを入力してください。" );
    fgets( buf, sizeof(buf), stdin );
    sscanf( buf, "%d", &value );

    add_elem( value );

    return CMD_RET_VALUE_CONTINUE;
}

/*
    deleteコマンドの実行
*/
enum CmdRetValue_tag cmd_delete(void)
{
    char buf[40];
    int value;

    puts( "削除する数値データを入力してください。" );
    fgets( buf, sizeof(buf), stdin );
    sscanf( buf, "%d", &value );

    if( delete_elem(value) >= 1 ){
        puts( "要素を削除しました。" );
    }
    else{
        puts( "削除する要素は見つかりませんでした。" );
    }

    return CMD_RET_VALUE_CONTINUE;
}

/*
    searchコマンドの実行
*/
enum CmdRetValue_tag cmd_search(void)
{
    char buf[40];
    int value;

    puts( "探索する数値データを入力してください。" );
    fgets( buf, sizeof(buf), stdin );
    sscanf( buf, "%d", &value );

    if( search_elem(value) == NULL ){
        printf( "%d は連結リスト中に存在しません。\n", value );
    }
    else{
        printf( "%d は連結リスト中に存在します。\n", value );
    }

    return CMD_RET_VALUE_CONTINUE;
}

/*
    clearコマンドの実行
*/
enum CmdRetValue_tag cmd_clear(void)
{
    clear_list();

    return CMD_RET_VALUE_CONTINUE;
}

/*
    printコマンドの実行
*/
enum CmdRetValue_tag cmd_print(void)
{
    print_list();

    return CMD_RET_VALUE_CONTINUE;
}

/*
    exitコマンドの実行
*/
enum CmdRetValue_tag cmd_exit(void)
{
    puts( "終了します。" );

    return CMD_RET_VALUE_EXIT;
}

/*
    要素を追加する

    引数：
        value:  追加する要素の数値データ。
*/
void add_elem(int value)
{
    // リストの末尾を探す
    struct LinkedList_tag* tail = search_tail();

    // 追加する要素を作る
    struct LinkedList_tag* elem = malloc( sizeof(struct LinkedList_tag) );
    if( elem == NULL ){
        fputs( "メモリ割り当てに失敗しました。", stderr );
        exit( 1 );
    }
    elem->value = value;
    elem->next = NULL;   // 末尾に追加するので、次の要素は無い

    // これまで末尾だった要素は、末尾から２番目の位置になる。
    // そのため、nextメンバを書き換えて、新たな末尾の要素を指すようにする。
    tail->next = elem;
}

/*
    要素を削除する

    引数：
        value：  削除する要素が持つ数値データ。
    戻り値：
        削除できた要素の個数を返す。
*/
int delete_elem(int value)
{
    struct LinkedList_tag* p = gHead.next;
    struct LinkedList_tag* prev = &gHead;
    int count = 0;

    while( p != NULL ){
        if( p->value == value ){
            // 削除する要素の１つ手前の要素の nextメンバを、
            // 削除する要素の次の要素を指すように書き換える
            prev->next = p->next;

            // 要素は malloc関数で生成したので、free関数による解放が必要。
            // 上記の prev->next = p->next よりも後で行わないと、不正なポインタが
            // prev->next に代入されてしまうことに注意。
            free( p );

            // 続行するなら、p を正しい要素を指すようにする
            p = prev->next;

            ++count;
        }
        else{
            prev = p;
            p = p->next;
        }
    }

    return count;
}

/*
    要素を空にする
*/
void clear_list(void)
{
    struct LinkedList_tag* p = gHead.next;
    struct LinkedList_tag* prev = &gHead;

    while( p != NULL ){
        // 削除する要素の１つ手前の要素の nextメンバを、
        //  削除する要素の次の要素を指すように書き換える
        prev->next = p->next;

        // 要素は malloc関数で生成したので、free関数による解放が必要。
        //  上記の prev->next = p->next よりも後で行わないと、不正なポインタが
        //  prev->next に代入されてしまうことに注意。
        free( p );

        p = prev->next;
    }
}

/*
    要素を出力する
*/
void print_list(void)
{
    struct LinkedList_tag* p = gHead.next;

    if( p == NULL ){
        puts( "リストは空です。" );
        return;
    }

    while( p != NULL ){
        printf( "%d\n", p->value );
        p = p->next;
    }
}

/*
    末尾の要素を探す

    戻り値：
        連結リストの末尾にある要素を指すポインタ。
*/
struct LinkedList_tag* search_tail(void)
{
    struct LinkedList_tag* p = &gHead;

    while( p->next != NULL ){
        p = p->next;
    }

    return p;
}

/*
    指定した値を持つ要素を探す

    引数：
        value：  探し出す要素が持つ数値データ。
    戻り値：
        先頭から連結リストをたどり、最初に見つけた value と同じ値を持つ要素のメモリアドレス。
        見つからなかった場合は NULL を返す。
*/
struct LinkedList_tag* search_elem(int value)
{
    struct LinkedList_tag* p = gHead.next;

    while( p != NULL ){
        if( p->value == value ){
            return p;
        }
        p = p->next;
    }

    return NULL;
}

/*
    標準入力から１行分受け取る

    受け取った文字列の末尾には '\0' が付加される。
    そのため、実際に受け取れる最大文字数は size - 1 文字。

    引数：
        buf:    受け取りバッファ
        size:   buf の要素数
    戻り値：
        buf が返される
*/
void get_line(char* buf, size_t size)
{
    fgets(buf, size, stdin);

    // 末尾に改行文字があれば削除する
    char* p = strchr(buf, '\n');
    if (p != NULL) {
        *p = '\0';
    }
}