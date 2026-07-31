		Mudos V22pre11 for WIN95/NT with COM extension Version 1.1
				Copyright (C) 1998,1999 
				      wwj,kcn
		
第一节 系统简介及部分改正的错误

第二节 LPC上的增强

第三节 LPC和COM extension混合编程

附录一 Mudos v22pre11 with COM extension中的COM对象


--------------------------------------------------------------------------------


第一节 系统简介及部分改正的错误


    Mudos V22pre11 for WIN95/NT with COM extension ( 以下简称
pre11 with COM)由清华大学计算机系王文军，周霖在Mudos V22pre11的基
础上开发而成。比较原版本的Mudos V22pre11来说，这个版本的Mudos改正
了一些错误，增加了对COM对象的支持。
    COM( Component Object Model )是Microsoft公司提出的一个开放
的面向对象技术。在Mudos中加入COM的支持，主要是为了能运用一些已有的
成熟技术和资源，弥补Mudos本身的功能不足。关于COM的具体说明请参看OLE
编程的资料。
    
    Mudos V22pre11已经改正了V21版中的不少错误，pre11 with COM则在这
个基础上又有大量的改动，应该说是一个很成熟的版本（已经在清华计算机系
楼内MUD上运行有半年多的时间）。以下是改动情况：
    
系统部分：
1. 修改 random 函数使之返回32位值，而不是WIN32平台中的16位
2. 修改了部分占用CPU时间过多的情况
3. 修改了 locatime 中的错误，使它不会在一天内循环
4. 修改lex.c 使编译时认识 8 进制数
5. 修改了 debug_error 函数，使它能报告 socket 错误
6. 增加了 set_this_player() efun
7. 增加了 rusage() efun，返回值如下：
   NT：
        int   ver     WINAPI GetVersion()的返回值
	int   utime   MUDOS用户态时间，单位：msec
	int   stime   MUDOS核心态时间
	int   load1   过去一分钟MUDOS占用机器时间的比率，
	 	      例：57% -> 5000 , 57.42% -> 5742
	int   load10  过去十分钟MUDOS占用机器时间的比率
	int   load15  过去十五分钟MUDOS占用机器时间的比率
   95/98:
        int   ver     WINAPI GetVersion()的返回值
	int   utime   机器运行时间，单位：msec
	int   stime   0
	int   load1   过去一分钟CPU利用率
	int   load10  过去十分钟CPU利用率
	int   load15  过去十五分钟CPU利用率
8. 修改了get_dir，使返回文件名为小写
9. 增加了配置界面。不再需要配置文件mudos.ini，配置改到registry
   HKEY_LOCAL_MACHINE\\wwj\\MudOS下
10.NT/95下支持多个MudOS Service实例，只要你的mudos.exe放在不同的
   目录下，或者exe文件名不同。
11.同时支持中文，英文NT/95。不会出现在英文操作系统下配置出乱码的
   情况。
12.允许>64人的登录。（上限1024，不过我想连接还没到那么多的
   时候MUDOS就当了）

COM部分：
1. 改进了LPC中COM class的定义，具体见后面的说明。
2. 修改了MString对象中的错误，使之不会有内存泄露的情况。
3. COM成员函数可以返回array,mapping,class等复杂类型。

	当你拿到Mudos v22pre11 for WIN95/NT with COM extension Version 1.1时，
它是一个zip文件，请用winzip展开，里面包含有执行文件与源码，在使用、分发、
修改它们时，请遵照GPL协议进行。
	Mudos.exe       编译好的执行文件，使用前先杀毒，防止传输中感染病毒
	                （不过在我这还是没有毒的）。
	                
	Readme.txt      是这个说明文档
	
	GPL.txt         GNU GENERAL PUBLIC LICENSE
	
	Mudos\*.*       MudOS的源码，用VC6.0编译通过
	
	BBS\lpc\*.*     一个LPC版本的BBS，没有写完，如果有谁愿意和我续写，请给
			wwj@www.telekbird.com.cn去信。
					
	BBS\bbscom\*.*  运行LPC版本BBS时一个必要模块的源码。
	
        BBS\FB270\*.*   Firebird BBS 2.70的源码
    
        testmud\*.*     一个测试连线的程序
    
        xyj\*.*         一个用于测试mudos的MUD《西游记》
    
    当你要启动mudos.exe时，请直接运行mudos.exe。它会弹出一个对话框让你输入
config文件位置，address server的端口，以及heart_beat时间。把它设成service
使得下次启动计算机时mud能自动运行，请在该对话框上点“注册服务”。当你配置
完了后，mudos就正式启动了。

    运行时会在explorer的那个状态条的右端加上一个"小地球"的ICON，以此表明它
正在运行。用鼠标点击它，会出现一个菜单，可以选择  About,Setup,Restart或
Shutdown。选Setup就会出现前面的那个配置对话框。

    当你在运行这个版本的mudos发现有什么问题时，请与下面的地址联系，我们会
尽量给你解答的。


    wwj    wwj@telekbird.com.cn
    kcn    mudos@126.com

 

--------------------------------------------------------------------------------


第二节 LPC上的增强



        Mudos v22pre11 with COM extension version 1.1 版本相比原V21版而言，LPC中
新增了class类型，新增了一些efunc，以下一一说明。

class类型类似于C中class,LPC的句法如下：

class class_name {
    type member_name1;
    type member_name2;
    ...
    
    type member_func(type var...);
};

声明一个class对象时句法是

	class class_name object_name;

使用对象之前应该先对对象初始化：
    
	object_name = new ( class class_name );

在引用class对象的成员时应该使用 -> 符号。

	object_name -> member_name1 = 0;

以下是一个LPC例子：

class ab
{
	int a;
	int add();
}

int ab::add() // ab的成员函数 add()
{
	return a++; // ab的成员变量 a++
}

class ab b;

useab()
{
	b=new(class ab);
	b->a=0; // b->a is 0
	b->add(); // then b->a is 1
}

	由于成员函数的出现，有必要支持在成员函数中访问本class，因此增加了
一个this关键字，用它来指示当前的class变量。如int ab::add()就可以写成
int ab::add()
{
	return this->a++;
}
	当然this主要的作用是将class自己传给别的函数。

	如果要定义COM对象，应该使用以下格式：
class class_name {
	member and member function ...
} = " com ";

	com是你要引用的com对象的CLSID或者ProgID或者DLL在MUD中的全路径，比如
Microsoft IE的HTML Viewer控件的CLSID是
        {EAB22AC3-30C1-11CF-A7EB-0000C05BAE0B}
ProgID是 
        Microsoft Web Browser Control
        
	class_name是你所使用的Interface的名字，如HTML Viewer控件的一个接口是 
IWebBrowser。
	class 的member和member function都应该是这个接口的属性和方法。通过
VC中带的OLE/COM Viewer可以看到Microsoft Web Browser Control的IWebBrowser
的定义是这样的（部分）。。。

[
	uuid(EAB22AC1-30C1-11CF-A7EB-0000C05BAE0B), // 这就是那个CLSID
	helpstring("Web Browser interface"), 
	hidden,
	dual
]

dispinterface IWebBrowser {
methods:

[id(0xfffffdda), helpstring("Refresh the currently viewed page.")]
void Refresh(); // 一个方法 

[id(0x00000068), helpstring("Navigates to a URL or file.")]
void Navigate( // 另一个方法 
[in] BSTR URL, 
[in] VARIANT* Flags, 
[in] VARIANT* TargetFrameName, 
[in] VARIANT* PostData, 
[in] VARIANT* Headers);

[id(0x000000ce), propget, helpstring("The horizontal position (pixels) of the frame window relative to the screen/container.")]
long Left(); 
    // 虽然写在methods里，但由于progget属性，实际上还是认为是属性，
    // 这是读属性值的方法

[id(0x000000ce), propput, helpstring("The horizontal position (pixels) of the frame window relative to the screen/container.")]
void Left([in] long rhs); 
    // 虽然写在methods里，但由于progput属性，实际上还是认为是属性，
    // 这是写属性值的方法

    // 等等。。。
}

变成LPC中可引用的class就该定义成：

class IWebBrowser {
	void Refresh();
	int Left;
} = "{EAB22AC1-30C1-11CF-A7EB-0000C05BAE0B}"; 
这个字符串可以另写为 Microsoft Web Browser Control
    
考察上面这个定义，与标准的C++对象定义没什么大的差别。成员Refresh
方法基本上于MIDL的定义没什么变化，Left属性的类型变成了int，Navigate
方法没加进来，这是因为在LPC与COM间类型转换时不是所有类型的参数都可以用
的。

目前的pre11 with COM extension支持以下类型转换：

	LPC中 int     与   COM中 int,long 互相转换。
	LPC中 string  与   COM中 BSTR     互相转换。
	LPC中 float   与   COM中 float    互相转换。
	LPC中 void    与   COM中 void     互相转换。
	LPC中 array   转成 COM中 IMValue * 。
	LPC中 class   转成 COM中 IMValue * 。
	LPC中 object  转成 COM中 IMValue * 。
	LPC中 mapping 转成 COM中 IMValue * 。

IMValue 接口在Mudos.exe中有定义。这里"互相转换"的意思是支持该类型作为
参数可以传递，也可以作为返回值，如属性的类型。对于无法转化的方法或属
性，不要写在class的定义中。

使用COM定义的class和普通的class相同，给出使用上面IWebBrowser的例子：

int UseIt()
{
	class IWebBrowser web;
	web=new (class IWebBrowser);
	web.Left=10;
	web.Refresh();
}

这里用IWebBrowser做例子的目的是说明如何使用COM对象，事实上IWebBrowser
不能在Mudos上使用(Mudos是一个telnet服务器，用不着一个浏览器)。下面是
另一个例子：

class IBbs {         // 必须是一个接口名，大小写敏感
    class IBbs QueryInterface(string);
    int  GetPlayerID(object);
    void SetEcho(int,int);
    void EnableKey(int,int);
    int  ThisPlayer();
}="/bin/obj/bbscom.dll";   // 也可以是 "{xxxx-xx...}" coclass GUID
   这里的"/bin/obj/bbscom.dll"是你的COM对象所在的DLL或OCX。用这
个定义方法不用在配置中加上com=...的说明(见原pre11 with COM extension
说明)，不用预先注册，限制是必须用全路径。

   QueryInterface是一个预定义的类成员函数，当你的类还有别的接口
的时候，你可以用这个函数来取得同一实例的另一接口（去掉了原来的
AssignInstance函数）。例：
class IBbs2 {
    int Test();
}="/bin/obj/bbscom.dll";
   你可以用以下的LPC代码
   IBbs  bbs;
   IBbs2 p;
   bbs=new(class IBbs);
   p=bbs->QueryInterface("IBbs2");
   则p是bbs所指定COM实例的另一个接口。


--------------------------------------------------------------------------------

第三节 LPC和COM extension混合编程


pre11 with COM extension本身提供了几个COM对象用于与外面的程序通讯，
具体定义请看附录一，在以后的说明中我将会提到 IMudos,IMValue,IMNumber,
IMString,IMReal,IMClass,IMObject,IMArray,IMMapping,IMProgram,
IMFunction这几个接口。

	首先你得建立一个ATL com dll的工程，然后新增加一个ATL Class。当你把
这个class取名为CTest时，你所得到的接口(Interface)名就成了ITest。然后你
就可以往这个Interface中添加属性和方法。

注意你所添加的属性类型只能是（不能有多余参数）
    int,BSTR,float
你所添加的方法返回类型只能是
    int,BSTR,float,IDispatch *
参数类型只能是
    int,BSTR,float,IDispatch *
对int,BSTR,float的处理和一般的COM一致。对IDispatch *的处理应该将它
传给IMValue对象，然后根据IMValue的Type()来GetExtend()取得相应类型的对象。
比如LPC中定义的class成员函数

	int Test(int i,class CTest c);

	对应的COM对象成员函数就该是：
	
MIDL interface:
	HRESULT Test([in] int i,[in] IDispatch *p,[out,retval] int *pVal);

MIDL dispinterface:
	int Test([in] int i,[in] IDispatch *p);
	
C++:
	STDMETHOD(Test)(int i,IDispatch *p,int *pVal);
	
	在Test中的实现时应该是这样的：

STDMETHODIMP CTest::Test(int i,IDispatch *p,int *pVal)
{
	// 这些接口的函数请查看生成的mudos.h
	if(!pVal)return S_FALSE;
	IMValue v(p);
	if(v.GetType()!=VP_CLASS)return S_FALSE; 
	IMClass c(v.GetExtend());

	// now use i,c
	// ...
	// return val in pVal
	return S_OK;
}

	你的对象可以声明两个方法作为事件响应：
MIDL interface: 
	HRESULT OnNewObject(IDispatch *p);
	HRESULT OnFreeObject();
	
在C++中的实现是：
	STDMETHODIMP CTest::OnNewObject(IDispatch *p)
	{
		m_os=new IMudos(p); // m_os是CTest的一个类型为IMudos *的成员变量
		return S_OK;
	}
	
	STDMETHODIMP CTest::OnFreeObject()
	{
		delete m_os;
		return S_OK;
	}
	这样在COM中就能使用IMudos的所有功能。
	
	具体实例请参看附带的BBSCOM和LPC BBS


--------------------------------------------------------------------------------


附录一 Mudos v22pre11 with COM extension中的COM对象


mudos.idl文件
// Generated .IDL file (by the OLE/COM Object Viewer)
// 
// typelib filename: MUDOS.DLL
// Forward declare all types defined in this typelib
interface IMValue;
interface IMNumber;
interface IMString;
interface IMReal;
interface IMObject;
interface IMClass;
interface IMMapping;
interface IMArray;
interface IMBuffer;
interface IMProgram;
interface IMFunction;
interface IMudos;

[
uuid(F64617C2-EA5A-11D1-B962-0080AD1480B3),
version(1.0),
helpstring("mudos v22pre11 Type Library")
]
library MUDOSLib
{
// TLib : OLE Automation : {00020430-0000-0000-C000-000000000046}
importlib("STDOLE2.TLB");

[
uuid(1B6ED8C0-EB38-11D1-BF0B-0000B4560A15),
helpstring("MValue Class")
]
coclass MValue {
[default] interface IMValue;
interface IMNumber;
interface IMString;
interface IMReal;
interface IMObject;
interface IMClass;
interface IMMapping;
interface IMArray;
interface IMBuffer;
};

[
odl,
uuid(1B6ED7C8-EB38-11D1-BF0B-0000B4560A15),
helpstring("IMValue Interface"),
dual,
oleautomation
]
interface IMValue : IDispatch {
[id(0x00000051), propget, helpstring("property Name")]
HRESULT _stdcall Name([out, retval] BSTR* pVal);
[id(0x00000052), propget, helpstring("property Type")]
HRESULT _stdcall Type([out, retval] eVALUETYPE* pVal);
[id(0x00000053), helpstring("method CreateNumber")]
HRESULT _stdcall CreateNumber();
[id(0x00000054), helpstring("method CreateString")]
HRESULT _stdcall CreateString();
[id(0x00000055), helpstring("method CreateReal")]
HRESULT _stdcall CreateReal();
[id(0x00000056), helpstring("method CreateArray")]
HRESULT _stdcall CreateArray([in] int size);
[id(0x00000057), helpstring("method CreateMapping")]
HRESULT _stdcall CreateMapping();
[id(0x00000058), propget, helpstring("property Extend")]
HRESULT _stdcall Extend([out, retval] IDispatch** pVal);
};

typedef enum {
VP_UNKNOW = 0,
VP_NUMBER = 1,
VP_STRING = 2,
VP_REAL = 3,
VP_OBJECT = 4,
VP_ARRAY = 5,
VP_MAPPING = 6,
VP_CLASS = 7,
VP_BUFFER = 8,
VP_FUNCTION = 9
} eVALUETYPE;

[
odl,
uuid(1B6ED7C0-EB38-11D1-BF0B-0000B4560A15),
helpstring("IMNumber Interface"),
dual,
oleautomation
]
interface IMNumber : IDispatch {
[id(0x00000001), propget, helpstring("property Number")]
HRESULT _stdcall Number([out, retval] int* pVal);
[id(0x00000001), propput, helpstring("property Number")]
HRESULT _stdcall Number([in] int pVal);
};

[
odl,
uuid(1B6ED7C1-EB38-11D1-BF0B-0000B4560A15),
helpstring("IMString Interface"),
dual,
oleautomation
]
interface IMString : IDispatch {
[id(0x0000000b), propget, helpstring("property String")]
HRESULT _stdcall String([out, retval] BSTR* pVal);
[id(0x0000000b), propput, helpstring("property String")]
HRESULT _stdcall String([in] BSTR pVal);
};

[
odl,
uuid(1B6ED7C2-EB38-11D1-BF0B-0000B4560A15),
helpstring("IMReal Interface"),
dual,
oleautomation
]
interface IMReal : IDispatch {
[id(0x00000015), propget, helpstring("property Real")]
HRESULT _stdcall Real([out, retval] single* pVal);
[id(0x00000015), propput, helpstring("property Real")]
HRESULT _stdcall Real([in] single pVal);
};

[
odl,
uuid(1B6ED7C3-EB38-11D1-BF0B-0000B4560A15),
helpstring("IMObject Interface"),
dual,
oleautomation
]
interface IMObject : IDispatch {
[id(0x0000001f), propget, helpstring("property ObjectName")]
HRESULT _stdcall ObjectName([out, retval] BSTR* pVal);
[id(0x00000020), propget, helpstring("property ObjectLoadTime")]
HRESULT _stdcall ObjectLoadTime([out, retval] int* pVal);
[id(0x00000021), propget, helpstring("property Environment")]
HRESULT _stdcall Environment([out, retval] IMObject** pVal);
[id(0x00000022), propget, helpstring("property ValueCount")]
HRESULT _stdcall ValueCount([out, retval] int* pVal);
[id(0x00000023), propget, helpstring("property Value")]
HRESULT _stdcall Value(
[in] int id, 
[out, retval] IMValue** pVal);
};

[
odl,
uuid(1B6ED7C5-EB38-11D1-BF0B-0000B4560A15),
helpstring("IMClass Interface"),
dual,
oleautomation
]
interface IMClass : IDispatch {
[id(0x00000033), propget, helpstring("property MemberCount")]
HRESULT _stdcall MemberCount([out, retval] int* pVal);
[id(0x00000034), propget, helpstring("property Member")]
HRESULT _stdcall Member(
[in] int id, 
[out, retval] IMValue** pVal);
};

[
odl,
uuid(1B6ED7C6-EB38-11D1-BF0B-0000B4560A15),
helpstring("IMMapping Interface"),
dual,
oleautomation
]
interface IMMapping : IDispatch {
[id(0x0000003d), propget, helpstring("property MappingCount")]
HRESULT _stdcall MappingCount([out, retval] int* pVal);
[id(0x0000003e), propget, helpstring("property MappingKeys")]
HRESULT _stdcall MappingKeys([out, retval] IMArray** pVal);
[id(0x0000003f), helpstring("method Query")]
HRESULT _stdcall Query(
[in] BSTR sKey, 
[out, retval] IMValue** pVal);
[id(0x00000040), helpstring("method Map")]
HRESULT _stdcall Map(
[in] BSTR sKey, 
[in] IMValue* pVal);
};

[
odl,
uuid(1B6ED7C4-EB38-11D1-BF0B-0000B4560A15),
helpstring("IMArray Interface"),
dual,
oleautomation
]
interface IMArray : IDispatch {
[id(0x00000029), propget, helpstring("property ItemCount")]
HRESULT _stdcall ItemCount([out, retval] int* pVal);
[id(0x0000002a), propget, helpstring("property Item")]
HRESULT _stdcall Item(
[in] int id, 
[out, retval] IMValue** pVal);
};

[
odl,
uuid(1B6ED7C7-EB38-11D1-BF0B-0000B4560A15),
helpstring("IMBuffer Interface"),
dual,
oleautomation
]
interface IMBuffer : IDispatch {
};

[
uuid(1B6ED8C1-EB38-11D1-BF0B-0000B4560A15),
helpstring("MProgram Class")
]
coclass MProgram {
[default] interface IMProgram;
};

[
odl,
uuid(1B6ED7C9-EB38-11D1-BF0B-0000B4560A15),
helpstring("IMProgram Interface"),
dual,
oleautomation
]
interface IMProgram : IDispatch {
[id(0x00000001), propget, helpstring("property FunctionCount")]
HRESULT _stdcall FunctionCount([out, retval] int* pVal);
[id(0x00000002), propget, helpstring("property Function")]
HRESULT _stdcall Function(
[in] int id, 
[out, retval] IMFunction** pVal);
[id(0x00000005), propget, helpstring("property FileName")]
HRESULT _stdcall FileName([out, retval] BSTR* pVal);
};

[
odl,
uuid(1B6ED7CA-EB38-11D1-BF0B-0000B4560A15),
helpstring("IMFunction Interface"),
dual,
oleautomation
]
interface IMFunction : IDispatch {
[id(0x00000001), propget, helpstring("property Name")]
HRESULT _stdcall Name([out, retval] BSTR* pVal);
[id(0x00000002), propget, helpstring("property ParamCount")]
HRESULT _stdcall ParamCount([out, retval] int* pVal);
[id(0x00000003), helpstring("method AddParam")]
HRESULT _stdcall AddParam([in] IMValue* pVal);
[id(0x00000004), helpstring("method ClearParam")]
HRESULT _stdcall ClearParam();
[id(0x00000005), propget, helpstring("property Ret")]
HRESULT _stdcall Ret([out, retval] IMValue** pVal);
[id(0x00000006), helpstring("method Apply")]
HRESULT _stdcall Apply();
};

[
uuid(1B6ED8C2-EB38-11D1-BF0B-0000B4560A15),
helpstring("MFunction Class")
]
coclass MFunction {
[default] interface IMFunction;
};

[
uuid(1B6ED8C3-EB38-11D1-BF0B-0000B4560A15),
helpstring("Mudos Class")
]
coclass Mudos {
[default] interface IMudos;
};

[
odl,
uuid(1B6ED7CB-EB38-11D1-BF0B-0000B4560A15),
helpstring("IMudos Interface"),
dual,
oleautomation
]
interface IMudos : IDispatch {
[id(0x00000001), propget, helpstring("property CurrentObject")]
HRESULT _stdcall CurrentObject([out, retval] IMObject** pVal);
[id(0x00000002), propget, helpstring("property CurrentProgram")]
HRESULT _stdcall CurrentProgram([out, retval] IMProgram** pVal);
[id(0x00000003), helpstring("method SetCommHook, pFunc is the function address.
int commhook(char *buf,int cursize,int maxsize,int user_id)")]
HRESULT _stdcall SetCommHook([in] int pFunc);
[id(0x00000004), helpstring("method Shutdown")]
HRESULT _stdcall Shutdown();
[id(0x00000005), propget, helpstring("property Users")]
HRESULT _stdcall Users([out, retval] IMArray** pVal);
[id(0x00000006), helpstring("method GetUser")]
HRESULT _stdcall GetUser(
[in] int UserId, 
[out, retval] IMObject** pVal);
[id(0x00000007), propget, helpstring("property HeartBeat")]
HRESULT _stdcall HeartBeat([out, retval] int* pVal);
[id(0x00000007), propput, helpstring("property HeartBeat")]
HRESULT _stdcall HeartBeat([in] int pVal);
};
};



请用VC5的classwizard选定MUDOS源码下的Mcon.tlb来自动生成Mcon.h 和 
Mcon.cpp，然后在mudos.h中加上以下定义（这些值是IMValue::Type()的
返回值）
typedef enum eVALUETYPE
{	VP_UNKNOW	= 0,
	VP_NUMBER	= VP_UNKNOW + 1,
	VP_STRING	= VP_NUMBER + 1,
	VP_REAL	=	VP_STRING + 1,
	VP_OBJECT	= VP_REAL + 1,
	VP_ARRAY	= VP_OBJECT + 1,
	VP_MAPPING	= VP_ARRAY + 1,
	VP_CLASS	= VP_MAPPING + 1,
	VP_BUFFER	= VP_CLASS + 1,
	VP_FUNCTION	= VP_BUFFER + 1
}	VALUETYPE;

const IID IID_IMNumber = {0x1B6ED7C0,0xEB38,0x11D1,{0xBF,0x0B,0x00,0x00,0xB4,0x56,0x0A,0x15}};


const IID IID_IMString = {0x1B6ED7C1,0xEB38,0x11D1,{0xBF,0x0B,0x00,0x00,0xB4,0x56,0x0A,0x15}};


const IID IID_IMReal = {0x1B6ED7C2,0xEB38,0x11D1,{0xBF,0x0B,0x00,0x00,0xB4,0x56,0x0A,0x15}};


const IID IID_IMObject = {0x1B6ED7C3,0xEB38,0x11D1,{0xBF,0x0B,0x00,0x00,0xB4,0x56,0x0A,0x15}};


const IID IID_IMArray = {0x1B6ED7C4,0xEB38,0x11D1,{0xBF,0x0B,0x00,0x00,0xB4,0x56,0x0A,0x15}};


const IID IID_IMClass = {0x1B6ED7C5,0xEB38,0x11D1,{0xBF,0x0B,0x00,0x00,0xB4,0x56,0x0A,0x15}};


const IID IID_IMMapping = {0x1B6ED7C6,0xEB38,0x11D1,{0xBF,0x0B,0x00,0x00,0xB4,0x56,0x0A,0x15}};


const IID IID_IMBuffer = {0x1B6ED7C7,0xEB38,0x11D1,{0xBF,0x0B,0x00,0x00,0xB4,0x56,0x0A,0x15}};


const IID IID_IMValue = {0x1B6ED7C8,0xEB38,0x11D1,{0xBF,0x0B,0x00,0x00,0xB4,0x56,0x0A,0x15}};


const IID IID_IMProgram = {0x1B6ED7C9,0xEB38,0x11D1,{0xBF,0x0B,0x00,0x00,0xB4,0x56,0x0A,0x15}};


const IID IID_IMFunction = {0x1B6ED7CA,0xEB38,0x11D1,{0xBF,0x0B,0x00,0x00,0xB4,0x56,0x0A,0x15}};


const IID IID_IMudos = {0x1B6ED7CB,0xEB38,0x11D1,{0xBF,0x0B,0x00,0x00,0xB4,0x56,0x0A,0x15}};

const CLSID CLSID_MValue = {0x1B6ED8C0,0xEB38,0x11D1,{0xBF,0x0B,0x00,0x00,0xB4,0x56,0x0A,0x15}};


const CLSID CLSID_MProgram = {0x1B6ED8C1,0xEB38,0x11D1,{0xBF,0x0B,0x00,0x00,0xB4,0x56,0x0A,0x15}};


const CLSID CLSID_MFunction = {0x1B6ED8C2,0xEB38,0x11D1,{0xBF,0x0B,0x00,0x00,0xB4,0x56,0x0A,0x15}};


const CLSID CLSID_Mudos = {0x1B6ED8C3,0xEB38,0x11D1,{0xBF,0x0B,0x00,0x00,0xB4,0x56,0x0A,0x15}};
