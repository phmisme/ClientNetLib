#include "EnginePrivate.h"

//版本说明：Windows操作系统需要定义宏：__WINDOWS__
//			Linux操作系统需要定义宏：__LINUX__
#ifndef __BASETYPE_H__
#define __BASETYPE_H__



/////////////////////////////////////////////////////////////////////////////////
//网络信息预定义宏
/////////////////////////////////////////////////////////////////////////////////
#ifndef FD_SETSIZE
#define FD_SETSIZE      1024
#endif /* FD_SETSIZE */


/////////////////////////////////////////////////////////////////////////////////
//当前包含的系统头文件引用
/////////////////////////////////////////////////////////////////////////////////
#if defined(__WINDOWS__)
#pragma warning ( disable : 4786 )
#pragma warning ( disable : 4996 )
	#include <Windows.h>
	#include "crtdbg.h"
#elif defined(__LINUX__)
	#include <sys/types.h>
	#include <pthread.h>
	//#include <execinfo.h>
	#include <signal.h>
	#include <exception>
	#include <setjmp.h>

    #define MSG_NOSIGNAL SO_NOSIGPIPE
#endif

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <math.h>
#include <stdarg.h>

//using namespace std;

///////////////////////////////////////////////////////////////////////
//标准数据类型定义
///////////////////////////////////////////////////////////////////////
#define VOID			void				//标准空
typedef unsigned char	UCHAR;			//标准无符号CHAR
typedef char			CHAR;			//标准CHAR
typedef unsigned int	uint;			//标准无符号INT
typedef int			INT;				//标准INT
typedef unsigned short	USHORT;			//标准无符号short
typedef short			SHORT;			//标准short
typedef unsigned long	ULONG;			//标准无符号LONG(不推荐使用)
typedef long			LONG;			//标准LONG(不推荐使用)
typedef float			FLOAT;			//标准float

typedef UCHAR			uchar;
typedef USHORT		ushort;
typedef uint			UINT;
typedef ULONG			ulong;
typedef ULONG			IP_t;
typedef USHORT		PacketID_t;
typedef INT			BOOL;
typedef UCHAR			BYTE;

//
typedef char					int8;
typedef unsigned char			uint8;
typedef unsigned char			uchar;
typedef short					int16;
typedef unsigned short			uint16;
typedef int					int32;
typedef unsigned int			uint32;
typedef unsigned int			uint;
typedef long long				int64;
typedef unsigned long long		uint64;




///////////////////////////////////////////////////////////////////////
//基本数据宏定义
///////////////////////////////////////////////////////////////////////

//IP地址的字符最大长度
#define IP_SIZE			24
#define KEY_SIZE			64
#define MAX_WORLDCOUNT			256
#define TIMELENTH			23


#define PACK_COMPART "$-$"//封包分隔符
#define PACK_COMPART_SIZE strlen(PACK_COMPART)

#ifndef ENCRYPT
#define ENCRYPT(x,xlen,KEY,BeginPlace)	if( (x)!=NULL ) \
		{ \
		\
			CHAR* t_pBuffer = (x); \
			CHAR* pKey = {KEY}; \
			UINT KeyLen = (UINT)strlen(pKey); \
			for (UINT i = 0; i < (xlen); i++) \
			{ \
				*t_pBuffer ^= pKey[(i+BeginPlace)%KeyLen]; \
				t_pBuffer++; \
			} \
		}
#endif

#ifndef ENCRYPT_HEAD
#define ENCRYPT_HEAD(x,KEY)	if( (x)!=NULL ) \
		{ \
			CHAR* t_pBuffer = (x); \
			CHAR* pKey = {KEY}; \
			UINT KeyLen = (UINT)strlen(pKey); \
			for (UINT i = 0; i < PACKET_HEADER_SIZE; i++) \
			{ \
				*t_pBuffer ^= pKey[i%KeyLen]; \
				t_pBuffer++; \
			} \
		}
#endif

#define OVER_MAX_SERVER 256

//无效的句柄
#define INVALID_HANDLE	-1
//无效的ID值
#define INVALID_ID		-1
//真
#ifndef TRUE
	#define TRUE 1
#endif
//假
#ifndef FALSE
	#define FALSE 0
#endif
//文件路径的字符最大长度
#ifndef _MAX_PATH
	#define _MAX_PATH 260
#endif

///////////////////////////////////////////////////////////////////////
//调试预定义宏定义
///////////////////////////////////////////////////////////////////////
#if defined(NDEBUG)
	#define __ENTER_FUNCTION_FOXNET if(1){
	#define __LEAVE_FUNCTION_FOXNET }
#else
	#define __ENTER_FUNCTION_FOXNET if(1){
	#define __LEAVE_FUNCTION_FOXNET }
#endif


#if defined(NDEBUG)
	#define _MY_TRY try
	#define _MY_CATCH catch(...)
#else
	#define _MY_TRY try
	#define _MY_CATCH catch(...)
#endif



//根据指针值删除内存
#ifndef SAFE_DELETE
#define SAFE_DELETE(x)	if( (x)!=NULL ) { delete (x); (x)=NULL; }
#endif
//根据指针值删除数组类型内存
#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(x)	if( (x)!=NULL ) { delete[] (x); (x)=NULL; }
#endif
//根据指针调用free接口
#ifndef SAFE_FREE
#define SAFE_FREE(x)	if( (x)!=NULL ) { free(x); (x)=NULL; }
#endif
//根据指针调用Release接口
#ifndef SAFE_RELEASE
#define SAFE_RELEASE(x)	if( (x)!=NULL ) { (x)->Release(); (x)=NULL; }
#endif


#endif
