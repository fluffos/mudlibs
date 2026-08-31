#ifdef __cplusplus
#define CXX
#define ARRLBAR {
#define ARRRBAR }
#define VOID void
#define CHARPTR char*
#define CHAR char
#define INT int
#else
#define ARRLBAR ({
#define ARRRBAR })
#define VOID   
#define CHARPTR string
#define CHAR   
#define INT   
#endif


