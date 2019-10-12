#ifndef __UTIL_STD_H__
	#define __UTIL_STD_H__


	#define OK					(0)			/* 状态值,代表正常 */
	#define ERROR				(-1) 		/* 状态值,代表错误 */

	#define OSTRUE				(1)			/* 逻辑值,代表正确 */
	#define OSFALSE				(0) 		/* 逻辑值,代表错误 */

	#define NULL 				(0)			/* 空指针数值 */


	#ifndef __ASMLANG__

	/* typedef - 类型定义 */
	typedef	int				BOOL;			/* 逻辑型变量类型 */
	typedef	int				STATUS; 		/* 状态型变量类型 */
	typedef	int				(*FUNCPTR)();	/* 函数指针变量类型 */

	typedef	char				I8;
	typedef	short				I16;
	typedef	int					I32;

	typedef	unsigned char		U8;
	typedef	unsigned short		U16;
	typedef	unsigned int		U32;
	typedef	unsigned long long	U64;
	typedef volatile U8			V_U8;
	typedef volatile U32		V_U32;
	
	typedef volatile U64		V_U64;//xuna

	typedef	float				F32;
	typedef	double				F64;

	#define FAST	register
	#define IMPORT	extern
	#define LOCAL	static

	#define NELEMENTS(array)  (sizeof (array) / sizeof ((array) [0]))

	#endif  //__ASMLANG__


#endif  /* __UTIL_STD_H__ */
