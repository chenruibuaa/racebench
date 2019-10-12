#ifndef __UTIL_STD_H__
	#define __UTIL_STD_H__


	#define OK					(0)			/* ״ֵ̬,�������� */
	#define ERROR				(-1) 		/* ״ֵ̬,������� */

	#define OSTRUE				(1)			/* �߼�ֵ,������ȷ */
	#define OSFALSE				(0) 		/* �߼�ֵ,������� */

	#define NULL 				(0)			/* ��ָ����ֵ */


	#ifndef __ASMLANG__

	/* typedef - ���Ͷ��� */
	typedef	int				BOOL;			/* �߼��ͱ������� */
	typedef	int				STATUS; 		/* ״̬�ͱ������� */
	typedef	int				(*FUNCPTR)();	/* ����ָ��������� */

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
