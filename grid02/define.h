#ifndef __define__
#define __define__

#define RETURN_SUCCESS 1
#define RETURN_FAILED 0
typedef int return_t;

//#define __debug__	//デバッグの時定義
#define __debug_calling__	//呼び出し関連のデバッグ時に定義
#define __debug_searching__	//検索関連のデバッグ時に定義
//#define __debug_pointing__	//画面座標取得モード時に定義
//#define __auto_input__

#define setting_path "../setting.ini"	//設定ファイルのパス

#define macro_continue 10	//マクロの循環定義防止


#define RETURN_SUCCESS	1
#define RETURN_FAILED	0

#define QUEUE_EXIT 1
#define QUEUE_CONTINUE 2

#define debug_message_line "\t------------------------------------------------------------"
#define debug_message_line_fatal "\t************************************************************"

#ifdef __debug__

#define debug_message_called(name) cui << debug_message_line << "\n\t\t" << (name) << " called.\n" << debug_message_line << "\n\n"
#define debug_message_returned(name) cui << debug_message_line << "\n\t\t" << "returned to " << (name) << "\n" << debug_message_line << "\n\n"

#else
#define debug_message_called(name) NULL
#define debug_message_returned(name) NULL

#endif

#endif
