/****************************************************************
 * This file is a part of the TianXia(天下, The World)'s MudLib.*
 * Please retain the header if you use it.     -- Micro@TianXia *
 ****************************************************************/

// File     : origin.h
// Purpose  : efun 函数 origin() 返回值定义头文件
// Created  : 1997-06-15
// By       : Micro@TianXia

// History  : 1997-06-15  Micro@TianXia 创建文件

#define ORIGIN_BACKEND          "driver"        // 向后兼容的需要
#define ORIGIN_DRIVER           "driver"        // 被 driver 调用，如心跳等
#define ORIGIN_LOCAL            "local"         // 被局部函数调用
#define ORIGIN_CALL_OTHER       "call_other"    // 被 call_other() 调用
#define ORIGIN_SIMUL_EFUN       "simul"         // 被 simul_efun 调用
#define ORIGIN_CALL_OUT         "call_out"      // 被 call_out() 调用
#define ORIGIN_EFUN             "efun"          // 被 efun 调用，如 sort_array 等
// call_other 函数指针和 efun 指针的假象
#define ORIGIN_FUNCTION_POINTER "function_pointer"    
#define ORIGIN_FUNCTIONAL       "functional"    // 被不知名函数调用
