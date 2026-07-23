//func_msg.h

mapping func_type = ([
	"string"	:	"字符",
	"obj"		:	"物件",
	"int"		:	"整数",
	"float"		:	"浮点",
	"map"		:	"映射",
	"file"		:	"文件",
	"mix"		:	"混合",
	"sys"		:	"系统",
	"arr"		:	"阵列",
	"buf"		:	"暂存",
	"unknow"	:	"未知",
]);

mapping funcs = ([

/*************************************************
**	A 开头 12 个				**
*************************************************/	
	"acos"	:	
	([
		"name" : "acos() - 传回一个浮点数 (float) 的反馀弦值 (arccosine).",
		"gram" : "float acos( float f );浮点数 acos( 浮点数 f );",
		"use"  : "传回参数 f 的反馀弦值, f 的单位是弪度 (radians).",
		"type" : "float",
	]),
	
	"add_action" :
	([
		"name" : "add_action() - 把区域函式 (local function) 
加进玩家可用的命令动词 (command verb).",
		"gram" : "void add_action(string | function fun,string | string *cmd,int flag );
无回传值 add_action( 字串 或 函数 fun, 字串 或 字串 *cmd, 整数 flag );",
		"use"  : @LONG
		
当玩家键入与 <cmd>  符合的命令时, 呼叫区域函数 
(local function) fun. 玩家命令中所打的参数 (argument), 
会以字串传入被呼叫到的函式. 如果命令错误, 则传回 0, 
没错则必须传回 1. 
如果第二个参数是一个阵列, 则所有在阵列中的命令会呼叫
第二个函式. 你可以用 query_verb() 找出呼叫函式的命令.
如果是错误的命令, 则会继续搜寻其他的命令, 直到找到相
符的命令、参数或传回错误讯息给玩家.
通常 add_action() 只会被 init() 的程序呼叫. 有定义附
加命令的物件必须是玩家可以接触到的: 玩家物件本身、被
玩家携带、玩家所处的房间、或是与玩家处於同一个房间的
物件.
如果参数 <flag> 是 1  , 只要参数前面的字元 (leading
characters) 符合动作命令 <cmd>  即可, 而整个动作命令
的字元 (entire verb) 会由 query_verb()  传回. 如果参
数是 2 , 结果同前, 但是 query_verb()  只会传回 <cmd>  
後面的字元 (characters following <cmd>).
LONG,
		"type" : "obj",
	]),	

	"all_inventory"	:
	([	
		"name" : "all_inventory() - 传回一个物件的内容物品.",
		"gram" : "object *all_inventory( object ob );物件 *all_inventory( 物件 ob );",
		"use"  : "传回一个阵列, 此阵列为物件 ob 的内容物品.",
		"type" : "obj",
	]),
		
	"all_previous_objects" :
	([
		"name" : "all_previous_objects() - 传回所有呼叫目前函式的物件阵列.",
		"gram" : "object *all_previous_objects();",
		"use"  : "传回一个所有呼叫目前函式的物件阵列 (an array of object). 
注意, 区域函式 (local function) 的呼叫不会更动目前的物
件(current object) previous_object()  的内容.",
		"type" : "obj",
	]),	

	"allocate" :
	([
		"name" : "allocate() - 配置记忆体给一个阵列 (array).",
		"gram" : "mixed *allocate( int size );混合 *allocate( 整数 size );",
		"use"  : "配置记忆体给一个有 size 个元素 (element)  的阵列. 
元素的数目必须大於 0, 而且不可以超过系统设定的上限
(通常约 10000 左右) . 所有元素的初始值 (initialized)
均为 0.	",
		"type" : "arr",
	]),
	
	"allocate_buffer" :
	([
		"name" : "allocate_buffer() - 配置记忆体给一个暂存区 (buffer).",
		"gram" : "buffer allocate_buffer( int size );
暂存区 allocate_buffer( 整数 size );",
		"use"  : "配置一块有 size 个元素 (elements) 的暂存区. 元素
的数目必须大於 0, 而且不可超过系统设定的上限值 
(通常是 10000 左右) . 所有阵列元素的初始值
(initialized) 均为 0.	",
		"type" : "buf",
	]),

	"allocate_mapping" :
	([
		"name" : "allocate_mapping() - 预先配置 (pre-allocate) 一块记
忆体给一个映射 (mapping).",
		"gram" : "mapping allocate_mapping( int size );
映射 allocate_mapping( 整数 size );",
		"use"  : @LONG
		
传回一个预先配置 size 个元素 (elements) 的映射.
□例:
	mapping x;
	int y = 200;
	x = allocate_mapping(y);
	y 是这个映射的初始大小. 如果您已经知道映射有多大, 
	使用 allocate_mapping 是比较好的方法 (在□例里是
200 个元素) , 因为一次就设定好要配置的记忆体, 就记忆体的
使用上是比较有效率的. 如果您要用映射储存 200 项资料, 用 
allocate_mapping 是较适合而有效率的方式.
	注意 !  如果您预计会删除映射中的许多项元素, 就应该
用 x = ([]) 来初始化□例中的映射 x, 而最好别用 
	allocate_mapping().
	注意: 在此, 实际上映射的大小是没有意义的.
	x = allocate_mapping( 200 ); 等於 x = ([]);
LONG,	
		"type"  :  "map",
	]),

	"apply"	:
	([
		"name" : "apply() - 处理函数指标 (function pointer).",
		"gram" : "mixed apply( mixed f, mixed *args )
混合 apply( 混合 f, 混合 *args )",
		"use"  : "如果 f 是一个函式, 就会呼叫 f 并用阵列 args 
当作 f	的参数 (argument).
	□例:
	apply( f, ({ 1, 2, 3 }) ); 与 
	evaluate( f, 1, 2, 3 ); 是相同的.",
		"type" : "mix",
	]),

	"arrayp" :
	([
		"name" : "arrayp() - 看一个给定的变数是否为阵列 (array).",
		"gram" : "int arrayp( mixed arg );整数 arrayp( 混合 arg );",
		"use"  : "如果 arg 是一个阵列, 就传回 1.",
		"type" : "arr",
	]),
	
	"asin"	:
	([
		"name" : "asin() - 传回一个浮点数 (float) 的反正弦值 (arcsine).",
		"gram" : "flaot asin( float f ); 浮点数 asin( 浮点数 f );",
		"use"  : "传回参数 f  的反正弦值, f 的单位是弪度 (radians).",
		"type" : "float",
	]),
	
	"atan" :
	([
		"name" : "atan() - 传回一个浮点数的正切值 (tangent).",
		"gram" : "float atan( float f );浮点数 atan( 浮点数 f );",
		"use"  : "传回参数 f  的反正切值, f 的单位是弪度 (radians).",
		"type" : "float",
	]),
	
	"author_stats" :
	([
		"name" : "author_stats() - 传回作者的一些统计资料.
domain_stats() - 传回区域的一些统计资料.",
		"gram" : "mapping author_stats( string domain | void );
mapping domain_stats( string domain | void );
映射 author_stats( 字串 domain 或 void );
映射 domain_stats( 字串 domain 或 void );",
		"use"  : @LONG
		
author_stats() 和 domain_stats()  都会传回一个储存在
映射变数的资料. 如果没有加上参数 (argument) , 就会传
回所有作者 (或所有区域) 每个人 (或每个区域) 的映射资
料. 每份映射资料包含有: 移动数 (moves), 耗费时间数 
(cost), 错误数 (errors),  心跳数 (heart_beats), 价值
数 (worth), 阵列数 (array_size),  和 物件数 (objects)
. 每一项都是包含在传回的映射变数中的整数值. 移动数是 
在指定作者 (或区域) 中, 物件被移动到另一物件中的多寡
. 耗费数是所有在指定作者 (或区域) 里的物件所耗费的计
算数目 (eval_cost). 错误数是在指定作者 (或区域) 中物
件总共发生的系统错误多寡. 心跳数是在指定作者 (或区域
) 中, 所有物件呼叫 heartbeat  的次数. 价值数则是使用
add_worth(3)  函数的情形 (这项数值常常用来追踪指定巫
师作者所流出和流入的金钱数目) . 阵列数是指定区域中阵
列所配置的记忆体位元数. 物件数是指定区域中被创造出来
的物件总数. 当这两个函数被呼叫时, 如果没有指定参数, 
传回的映射就会像这样:
	([ domain0 : info0, domain1 : info1, ... ])
而 info0 的内容格式是: mapping形式
LONG,
		"type" : "sys",
	]),

/*************************************************
**	B 开头 3 个				**
*************************************************/	
	
	"bind" :
	([
		"name" : "bind() - 变更一个函式指标 (function pointer) 所指向的函式. ",
		"gram" : "function bind( function f, object ob )
函式指标 bind( 函式 f, 物件 ob )",
		"use"  : @LONG
		
传回一个指向 f  的函式指标, 但是指标属於物件 ob , 
而不是创造 f  的物件. 如果 f  的创造者被摧毁、f 
是一个超越函式 (emulated function,  即 efun)  的
指标、或是指标指向的超越函式会对 this_object  做
一些处理时,  bind() 就很有用.
□例:
	void make_living(object ob) 
	{
	function f;
	f = bind( (: enable_commands :), ob );
	evaluate(f);
	}
以上例子的作用, 相当於物件 ob 自己处理 
enable_commands() 的超越函式. 注意 !! 这个例子会引
发一些系统安全上的风险, 因为 bind() 可以让你强迫其
他的物件执行一段程式码. 为了要防止 bind() 被滥用,
有一个主宰物件函式 (master apply) valid_bind()  可
以用来决定 bind() 的执行与否. 呼叫 bind() 时, 如果
valid_bind() 传回 1 即可执行, 传回 0  就无法执行.
LONG,
		"type"  : "unknow",
	]),
	
	"break_string" :
	([
		"name" : "break_string() - 以固定的间隔打断一个字串 (string).",
		"gram" : "string break_string( string str | int foobar, int len,
void | int indent | string indent );
			字串 break_string( 字串 str 或 整数 foobar, 整数 len,
无参数 或 整数 indent 或 字串 indent );",
		"use"  : "break_string() 以每 len  个字元 (character) 打断一个
没有换行的字串, 并在每一个打断的片段後面换行. 如果 
indent 是一个字串, 那每个片段在换行之前会加上 indent.
如果第一个参数 (argument) 是一个整数, break_string()
就只会传回 0.
错误:
	break_string()  的处理完全与字串内容无关. 这个函式不
会认得句号 '.' 和换行 '\n' .  所以这个函式执行的结果, 
不见得会如你预期的一样. 我的经验是: 您应该在句号之後
加一个空白, 也别加上 '\n' , 然後再使用 break_string()
. 您也许不会喜欢用 break_string() 提供的格式. 在往後
MudOS 的版本里, 也许会让 break_string() 认得 '\n' . ",
		"type" : "string",
	]),
	
	"bufferp" :
	([
		"name" : "bufferp() - 看一个给定的变数是否为一个暂存区 (buffer).",
		"gram" : "int bufferp( mixed arg );整数 bufferp( 混合 arg );",
		"use"  : "如果 arg 是一个暂存区就传回 1, 不是就传回 0.",
		"type" : "buf",
	]),
	
/*************************************************
**	C 开头 16 个				**
*************************************************/	
	"cache_stats" :	
	([
		"name" : "cache_stats() - 报告驱动程式 (driver) 和 Mud 函式库
(mudlib) 的变化统计资料.",
		"gram" : "void cache_stats( void );无传回值 cache_stats( void );",
		"use"  : "这个函式只有在编译驱动程式时, options.h 中有定义 
cache_stats 才有用. 这个超越函式 (emulated function
, 即 efun)  会列出 call_other() 的快取 (cache)效率.",
		"type" : "sys",
	]),
	
	"call_other" :
	([
		"name" : "call_other() - 呼叫在另一个物件中的函式.",
		"gram" : "unknown call_other( object ob | object *obs,
string func | mixed *args, ... );
未知 call_other( 物件 ob 或 物件 *obs,字串 func 或 混合 *args, ... );",
		"use" : @LONG
		
用可以选择的参数 (argument) 呼叫另一个物件中的函式.
传回值要视被呼叫的函式而定, 所以使用此一函式时最好
检查传回值. func  是物件 ob 中被呼叫的函式名称, 而
第三个、第四个... 等等的参数, 则会传入 func 中, 当
成 func 的第一个、第二个参数. 在 call_other() 中, 
如果第一个参数是一个物件阵列, call_other()  就会逐
一呼叫它们, 而传回值也会变成一个阵列. 如果第二个参
数是一个阵列, 那阵列中的第一个元素 (element)  必须
是一个字串 (即要呼叫的函式) , 而其他的元素就会被当
成要传入此函式的参数.
	这里有个使用 call_other() 更好的方法:
object ob 或 object *obs -> func( ... );
□例:
	call_other( ob, "query", "name" );
可以写成
	ob->query("name");
如果 call_other() 的第二的参数是一个阵列, 也可以把
上例写成:
	call_other( ob, ({ "query", "name" }));
这里有一个使用阵列的□例:
	users()->quit();
LONG,	
		"type" : "obj",
	]),
	
	"call_out_info" :
	([
		"name" : "call_out_info() - 取得延迟中的 call_out() 资讯.",
		"gram" : "mixed *call_out_info( void );",
		"use"  : "取得所有使用 call_out() 呼叫而延迟中的函式呼叫资讯.
这会传回一个阵列, 每一项有四个元素 (element):
物件 (object), 函数 (function), 延迟时间 (the delay
to go), 选择的参数 (the optional argument).",
		"type" : "mix",
	]),
	
	"capitalize" :
	([
		"name" : "capitalize() - 把一个字串的第一个英文字元(character) 转成大写.",
		"gram" : "string capitalize( string str );",
		"use"  : "把传入字串 str 的第一个英文字元转成大写, 并传回一个
转换後的字串.",
		"type" : "string",
	]),
	
	"catch"	:
	([
		"name" : "catch() - 找出函式运作的错误.",
		"gram" : "mixed catch( mixed expr );",
		"type" : "sys",
		"use"  : "处理 expr 式子. 如果没有出错就传回 0  , 如果有标准
错误, 则传回一个第一个字元是 * 的字串.
函式 throw()  也可以用来马上传回任何非零值. catch()
实际上并不是真正的函式呼叫, 而是编译器 (compiler)
的一个指令.
catch() 有点耗费系统资源, 请您别到处用它. 把 catch()
放在出错时可能会摧毁系统结构 (consistency)  的地方.",
	]),
	
	"ceil" :
	([
		"name" : "ceil() - 把一个浮点数进位成最近的整数值.",
		"gram" : "float ceil( float f );",
		"type" : "float",
		"use"  : "传回一个最接近 f  而且等於或大於 f  的整数浮点数, 
即 f  的小数位都无条件进位成整数.",
	]),
	
	"children" :
	([
		"name" : "children() - 传回一个指定物件 (object) 所复制出来的
物件阵列.",
		"gram" : "object * children( string name );",
		"type" : "obj",
		"use"  : @LONG
		
这个函式传回一个物件阵列 (array), 物件群则是档案名称
为 name 的物件所复制出来的. 一个使用的□例是找出所有
从使用者物件 (user object)  复制出来的物件:
object *list;
list = children("/obj/user");
这样可以让您找出所有的使用者 (包括已经断线的使用者),  而
users() 只会回报还能互动的 (interactive) 使用者.	
LONG,
	]),
	
	"clone_object" :
	([	
		"name" : "clone_object() - 载入一个物件的复制物件",
		"gram" : "object clone_object( string name );",
		"type" : "obj",
		"use"  : "根据定义的 name 载入一个新的物件 (object) , 并且给此
物件一个独有的名称. 此函式传回一个新的物件. 一个物件
的 environment()  传回值如果不为 0  的话, 就无法复制.",
	]),
	
	"clonep" :
	([
		"name" : "clonep() - 检查给定的一个变数是否为复制的物件.",
		"gram" : "int clonep( void | mixed arg );",
		"type" : "obj",
		"use"  : @LONG
		
如果参数 arg 有设定 objectp() 和 O_CLONE 旗标 (flag),
此函式就传回「真」 (true) 的值 (也就是 1). MUD 的
驱动程式 (driver) 会对经由 new(3) (clone_object(3))
创造出来的物件, 设定 O_CLONE  旗标. clonep() 函式
对於主物件 (master copy,  经由 call_other(3) 载入) 不
会传回「真」值. 请注意, 如果 clonep() 传回「真」值,
则 file_name()  对此物件传回的档案名称会加上 #n ( n
为整数). clonep() 不加上参数则预定物件为 this_object().
LONG,
	]),
	
	"command" :
	([
		"name" : "command() - 如同该物件般, 执行一个命令.",
		"gram" : "int command( string str, object ob );",
		"type" : "obj",
		"use"  : "让物件 ob 执行 str  的命令. 如果不指定 ob , 则视同为
this_object().  请注意, 第二个参数可以使用的□围是由
该 MUD  的系统管理者所决定, 所以您经常无法使用您所指
定的物件动作. 如果该物件无法执行命令, 函式则会传回 0
值. 如果可以执行, 则会传回一个数字. 此数字是 LPC  执
行的该命令的「执行花费时间」 (evaluation cost). 数字
越大则此命令就越费时, 但是这个数字并不够精确, 其所使
用的量度 (scale)  是主观 (subjective) 而不可靠
(unreliable)  的.",
	]),
	
	"commands" :
	([
		"name" : "commands() - 传回一些关於此使用者可以使用的命令资讯",
		"gram" : "mixed *commands( void );",
		"type" : "sys",
		"use"  : @LONG
		
传回一个包含四项资料的阵列 (array), 说明 this_object()
可以使用的动作 (action) . 第一项资料是命令名称 ( 即
add_action()  的命令) ; 而第二项是命令的旗标 (flags)
(即 add_action() 的第三个参数, 预设值为 0  );  第三项
资料是定义此动作的物件. 第四项资料是被此动作呼叫的函式
(function) (此项资料如果是个函式指标 [function pointer]
则传回 "<function>").
LONG,
	]),
	
	"cos" :
	([
		"name" : "cos() - 传回一个浮点数的馀弦值 (cosine)",
		"gram" : "float cos( float f );",
		"type" : "float",
		"use"  : "传回参数 f 的馀弦值, f  以弪度 (radians) 为单位.",
	]),
	
	"cp" :
	([
		"name" : "cp() - 复制一个档案",
		"gram" : "int cp( string src, string dst );",
		"type" : "string",
		"use"  : "复制档案 src 为档案 dst.传回值:如果复制成功
就传回 1, 失败则传回负值.",
	]),
	
	"crc32" :
	([
		"name" : "crc32() - 计算一个暂存区或字串的循环重覆码(cycle redundency code)",
		"gram" : "int crc32( buffer | string x );",
		"type" : "sys",
		"use"  :"计算并传回给定的暂存区或是字串 x 的 CRC-32 码.",
	]),
	
	"crypt" :
	([
		"name" : "crypt() - 对一个字串进行编码.",
		"gram" : "string crypt( string str, string seed );",
		"type" : "string",
		"use"  : @LONG
		
以字串 seed 的前两个字元当作种子数, 对字串 str  进行
编码. 如果 seed 为 0  , 就会用随机数字进行编码.
LONG,
	]),
	
	"ctime" :
	([
		"name" : "ctime() - 传回一个时间字串",
		"gram" : "string ctime( int clock );",
		"type" : "string",
		"use"  : "传回一个日期和时间的字串, 而参数 clock 是自从
1970 年算起的秒数.",
	]),
	
/*************************************************
**	D 开头 9 个				**
*************************************************/	
	"debug_info" :
	([
		"name" : "debug_info() - 显示除错 (debug) 资讯",
		"gram" : @LONG
		
		mixed debug_info( int operation, ... );
		mixed debug_info( 0, object ob );
		mixed debug_info( 1, object ob );
LONG,
		"type" : "sys",
		"use"  : @LONG
		
debug_info()  是一个普通用途的措施, 用来为 MudOS
驱动程式除错. 而所需要的除错资讯则由第一个参数决定. 
其馀的参数则由第一个参数的动作 (operation)  决定.
存在的动作 (0 与 1) 需要第二个物件参数, 而可能用来显示
MudOS 物件结构的不同□围 ( various fields of the MudOS
object structure).

以下的 LPC 码用来产生一个简单的输出结果:
程式一:
/* di0.c */
create() 
{
debug_info(0, this_object());
}
结果一:
O_HEART_BEAT      : FALSE
O_IS_WIZARD       : FALSE
O_ENABLE_COMMANDS : FALSE
O_CLONE           : FALSE
O_DESTRUCTED      : FALSE
O_SWAPPED         : FALSE
O_ONCE_INTERACTIVE: FALSE
O_RESET_STATE     : FALSE
O_WILL_CLEAN_UP   : FALSE
O_WILL_RESET: TRUE
total light : 0
next_reset  : 720300560
time_of_ref : 720299416
ref         : 2
swap_num    : -1
name        : 'u/snowtu/di0'
next_all    : OBJ(bin/dev/_update)
This object is the head of the object list.

程式二:
/* di1.c */
create() 
{
debug_info(1, this_object());
}
结果二:
program ref's 1
Name u/snowtu/di1.c
program size 10
num func's 1 (16)
num strings 0
num vars 0 (0)
num inherits 0 (0)
total size 104
LONG,
	]),

	"debugmalloc" :
	([
		"name" : "debugmalloc() - 将已配置的记忆体 (malloc'd memory) 
资讯倾印到一个档案里.",
		"gram" : "void debugmalloc( string filename, int mask );",
		"type" : "sys",
		"use"  : "这个超越函式 (efun) 必须在编译驱动程式 (driver) 时
, 於 options.h  同时定义 DEBUGMALLOC 和 
DEBUGMALLOC_EXTENSIONS  两者才有效. debugmalloc()
会倾印 DMALLOC()  配置的记忆体区块的资讯及相关的
macros. (如果 macro 有 mask bitwise and'd (&) with
the tag, 即 mask & tag  不是零) 详细情形请参阅驱动
程式原始码中的 md.c 及 config.h	",
	]),
	
	"deep_inherit_list" :
	([
		"name" : "deep_inherit_list() - 取得一个物件所继承的父物件.(parent object)",
		"gram" : "string *deep_inherit_list( object obj );",
		"type" : "obj",
		"use"  : "传回一个物件所继承之所有父物件的档案名称, 包括直接继承
与间接继承的父物件.",
	]),
	
	"deep_inventory" :
	([
		"name" : "deep_inventory() - 传回一个物件的内容物品, 如果物品中
会以还含有物品, 将会以巢状的方式继续找下去.",
		"gram" : "object *deep_inventory( object ob );",
		"type" : "obj",
		"use"  : "传回 ob 含有之所有物品的阵列 (array), 深层的物品也
会继续寻找下去.	",
	]),
	
	"destruct" :
	([
		"name" : "destruct() - 从游戏中销毁一个物件.",
		"gram" : "void destruct( object ob );",
		"type" : "obj",
		"use"  : "完全摧毁物件 ob. 在呼叫 destruct() 之後, 会清除所有
的全域变数 (global variables), 只剩下区域变数和参数.
如果 ob 是 this_object() , 此函式仍会执行, 但是最好
立刻传回一个数值.",
	]),
	
	"disable_commands" :
	([
		"name" : "disable_commands() - 设定一个活著的 (living) 物件为
「非活著」(non-living)",
		"gram" : "int disable_commands( void );",
		"type" : "obj",
		"use"  : "让一个活著的物件变成「非活著」(non-living). 所谓
「非活著」, 就是让物件变成以下的状态:
	add_actions 失效.
	livingp 函式传回「伪」值 (false, 0).
	如果此物件是「可互动的」 (interactive), 就让这个使用者
无法输入命令 (input_to 函式例外).
	disable_commands 永远传回 0 值.",
	]),
	
	"disable_wizard" :
	([
		"name" : "disable_wizard() - 取消一个物件的巫师特权.",
		"gram" : "void disable_wizard( void );",
		"type" : "obj",
		"use"  : "这个函式与 enable_wizard() 函式的功用相反. 把目前
物件的巫师特权取消掉.",
	]),
	
	"domain_stats" :
	([
		"name" : "domain_stats() - 传回区域的一些统计资料.
author_stats() - 传回作者的一些统计资料.",
		"gram" : "mapping domain_stats( string domain | void );
mapping author_stats( string domain | void );",
		"type" : "sys",
		"use"  : @LONG
		
author_stats() 和 domain_stats()  都会传回一个储存在
映射变数的资料. 如果没有加上参数 (argument) , 就会传
回所有作者 (或所有区域) 每个人 (或每个区域) 的映射资
料. 每份映射资料包含有: 移动数 (moves), 耗费时间数 
(cost), 错误数 (errors),  心跳数 (heart_beats), 价值
数 (worth), 阵列数 (array_size),  和 物件数 (objects)
. 每一项都是包含在传回的映射变数中的整数值. 移动数是 
在指定作者 (或区域) 中, 物件被移动到另一物件中的多寡
. 耗费数是所有在指定作者 (或区域) 里的物件所耗费的计
算数目 (eval_cost). 错误数是在指定作者 (或区域) 中物
件总共发生的系统错误多寡. 心跳数是在指定作者 (或区域
) 中, 所有物件呼叫 heartbeat  的次数. 价值数则是使用
add_worth(3)  函数的情形 (这项数值常常用来追踪指定巫
师作者所流出和流入的金钱数目) . 阵列数是指定区域中阵
列所配置的记忆体位元数. 物件数是指定区域中被创造出来
的物件总数. 当这两个函数被呼叫时, 如果没有指定参数, 
传回的映射就会像这样:
	([ domain0 : info0, domain1 : info1, ... ])
而 info0 的内容格式是:
([ "moves" : moves, "cost" : cost, "errors" : errors,
   "heart_beats" : heart_beats, "worth" : worth,
   "array_size" : array_size, "objects" : objects ])
有指定参数时, 就会传回像 info0 的格式.
LONG,
	]),
	
	"dumpallobj" :
	([
		"name" : "dumpallobj() - 报告所有载入之物件的一些统计资料.",
		"gram" : "void dumpallobj( string | void );",
		"type" : "sys",
		"use"  : "这个函数会印出所有已经载入之物件列表. 如果没有指定
参数, 这些资讯会倾印在 /OBJ_DUMP  这个档案里. 如果
有指定参数, 则参数就是指定要输出的档案名称.",
	]),
	
/*************************************************
**	E 开头 14 个				**
*************************************************/	
	"each" :
	([
		"name" : "each() - 分次传回一个映射变数 (mapping) 的各个(key, value) 的内容.",
		"gram" : "mixed *each( mapping m, int reset );",
		"type" : "mix",
		"use"  : @LONG
		
each()  函式把一个映射变数里的每对 (key, value) 一次
一次地传回. each() 传回来的次序与 keys() 和 values()  
两个函式传回来的次序一样. 当 each() 读到映射变数的尾
端时, 会传回一个空的向量 (null vector, 即 (0,0)). 而
在传回空向量之後, 下一个 each() 传回的内容又会从头开
始. 
当不同的物件使用 each() 读取相同的映射变数时, 一定都会
从头开始. 虽然 MudOS 有单执行绪 (single thread) 的性质
, 但是也不致於让 each() 执行时出现问题. ( 实际上一个物
件无法於使用 each() 读取映射函数读到一半时, 跳开目前读
(key, value) 的位置)
如果指定第二个参数为 1, 则 each() 会重新从头开始读取.

□例:
	mixed *pair;
	while ((pair = each(x)) != ({})) 
		{
		write("key   = " + pair[0] + "\n");
		write("value = " + pair[1] + "\n");
		}	
LONG,
	]),
	
	"ed" :
	([
		"name" : "ed() - 编辑一个档案.",
		"gram" : "void ed( string file, string exit_fn, int restricted );
void ed( string file, string write_fn, string exit_fn,int restricted );",
		"type" : "obj",
		"use"  : @LONG

这个函式只有在定义了 __OLD_ED__ 之後有效.
这个函式很有趣. 它会启动一个文书编辑程式来编辑一个指定
的档案. 这个程式与 UNIX 的 ed 程式几乎相容. 当你进入这
个程式後, 可以输入 h 了解用法.
write_fn  函式可以让 mudlib 控制档案的写入权限和档案修
改纪录. 当编辑程式写入一个档案时, MUD 驱动程式 (driver)
会呼叫 write_fn 两次. 第一次呼叫时, 是在写入档案之前,
而 flag 旗标为 0. 如果被呼叫的函式传回「真」值 (true, 
即为非零值) , 编辑程式就会继续写入档案. 第二次呼叫时, 
是在写入档案完成之後, 此时的 flag 旗标为非零值. 被呼叫
的函式必须符合以下的格式:
	int write_fn(string fname, int flag)
离开编辑程式时, MUD 驱动程式 (driver) 会呼叫 exit_fn
函式. 这个被呼叫的函式可以让 mudlib 清除. 这个函式要
符合以下的格式:
	void exit_fn()
而可以省略的 restricted 旗标则限制编辑程式的功能.
像是: 插入一个档案, 以不同的名字储存档案. 这些功能
在 restricted 旗标为「真」值时, 就无法使用.
LONG,
	]),
	
	"ed_cmds" :
	([
		"name" : "ed_cmd() -  对一个正在执行的 ed 工作 (session)  
送出一个命令.",
		"gram" : "string ed_cmd( string cmd )",
		"type" : "obj",
		"use"  : "这个函式只有在 __OLD_ED__ 不予定义 (define) 时有效.
命令 cmd 会被送到一个正在执行的 ed 工作 (session) , 
并传回命令执行後输出的结果.",
	]),
	
	"ed_start" :
	([
		"name" : "ed_start() - 开始执行一个 ed 工作.",
		"gram" : "string ed_start( string file | void, 
int restricted | void )",
		"type" : "obj",
		"use"  : "这个函式只有 __OLD_ED__ 不予定义 (define) 时有效.
这个函式开始执行内部的文书编辑程式, 可以指定或不指定
要予以编辑的档案 file.  函式会传回执行完 ed 的编辑结
果. 当 ed 程式仍在执行时, 可以使用 ed_cmd() 执行 ed 
的命令.
如果 restricted 的值为 1  , 所有更改档案的命令都会被
视为无效.
一个物件同一时间内只能执行一个 ed 工作.	",
	]),
	
	"enable_commands" : 
	([
		"name" : "enable_commands() - 允许物件使用玩家 (player) 的命令.",
		"gram" : "void enable_commands( void );",
		"type" : "obj",
		"use"  : @LONG

enable_commands() 把 this_object()  标记为活著 (living)
的物件, 并允许它使用 add_action() 所加入的命令 (要使用
command() 函式) . 呼叫 enable_commands() 时, MUD  驱动
程式 (driver) 会寻找内部的 catch_tell() 函式. 如果找到
了此函式, 每一次有讯息传给此一个物件时 (例如 say() )  
, 驱动程式就会呼叫 catch_tell() 一次.
已知的问题:
	请勿在 create() 函式以外的地方呼叫 enable_commands()
否则会出现奇怪的问题.
LONG,
	]),
	
	"environment" : 
	([
		"name" : "environment() - 传回一个物件所身处的环境.",
		"gram" : "object environment( object ob );",
		"type" : "obj",
		"use"  : "传回含有物件 ob 的环境物件. 如果没有指定参数 (argument)
, ob 预设为 this_object().",
	]),
	
	"error"	:
	([
		"name" : "error - 产生一个执行时段 (run_time) 错误.",
		"gram" : "void error( string err );",
		"type" : "sys",
		"use"  : "呼叫 error() 时, 会产生一个执行时段错误 err. 并中止
目前正在执行的执行绪脉络 (thread). 而发生错误的程式
会被追踪错误的出处, 并纪录在除错纪录 (debug log) 的
档案中.	",
	]),
	
	"errorp" :
	([
		"name" : "errorp() - 判断一个指定的变数是否为错误码 (error code).",
		"gram" : "int errorp( mixed arg );",
		"type" : "sys",
		"use"  : @LONG

如果参数 arg  是一个整数值的错误码, errorp() 传回 1 .
您可能会修改超越函式 (emulated functions, efun), 而能
传回一个标准的错误码. 所以程式可以写成像下面的样子:
	if (errorp(result = efun_call()))
		printf("error = %d\n", result);
LONG,
	]),
	
	"eval_cost" :
	([
		"name" : "eval_cost() - 传回执行耗费时间 (evaluation cost) 还
剩多少.",
		"gram" : "void eval_cost()",
		"type" : "sys",
		"use"  : "eval_cost() 在驱动程式 (driver) 判断此时是否陷入一个
无穷回圈之前, 传回是否可以执行的指示数字.",
	]),
	
	"evaluate" :
	([
		"name" : "evaluate() - 执行一个函式指标 (function pointer)",
		"gram" : "mixed evaluate(mixed f, ...)",
		"type" : "unknow",
		"use"  : "如果 f  是一个函式, 就会以第二个参数以後 (即上面 ...
的地方) 为 f  使用的参数呼叫 f. 而 f  如果有传回值, 
evaluate( f, ... )  就相当于直接呼叫 f  的结果. ",
	]),
	
	"exec" :
	([
		"name" : "exec() -  将一个可互动的 (interactive) 玩家 (player) 
物件切换连结 (connection) 到另外一个物件上.",
		"gram" : "int exec( object to, object from );",
		"type" : "obj",
		"use"  : @LONG

这个函式允许指定的物件把可互动的连结 (link) 迁移到另
外一个物件上. 也就是说, 成功地执行 exec( to, from )
之後, interactive( to ) 会传回 1, 而 interactive( from )
会传回 0. 而控制 from 的玩家会转移控制权到 to 的身上.
请注意这个函式的权力非常大, 不当地使用会危及 MUD  的
系统安全. 正确地限制使用此函式的方法是另外写一个同名的
模拟超越函式 (simulated emulated function, simul_efun)
, 并使用 valid_override(4)  来限制此一模拟超越函式的使
用. (意即 efun::exec() )
exec() 函式在成功地转换之後传回 1, 转换失败则传回 0.	
LONG,
	]),
	
	"exp" :
	([
		"name" : "exp() - 以一个浮点数为指数, 自然对数 e  为底数
计算其值.",
		"gram" : "float exp( float f );",
		"type" : "float",
		"use"  : "exp() 传回 e^f 的值.	",
	]),
	
	"explode" :
	([
		"name" : "explode() - 打断一个字串.",
		"gram" : "string *explode( string str, string del );",
		"type" : "string",
		"use"  : "explode() 传回一个字串的阵列 (array), 此阵列是
字串 str 以 del 分界打断的片段.
□例:
	explode( str, " " );
	这样会传回一个 str 中所有英文单字的字串阵列 (假设
str 是英文句子, 每一个单字由空白字元隔开).",
	]),
	
	"export_uid" :
	([
		"name" : "export_uid() -  设定一个物件的使用者识别名称 (user id,
uid).",
		"gram" : "int export_uid( object ob );",
		"type" : "obj",
		"use"  : "设定 ob 的使用者识别名称 (uid) 为 this_object() 的
有效使用者识别名称 (effective user id, effective uid).
这个函式只有在 ob 的有效使用者识别名称为 0 时有效.",
	]),
	
		
		
]);