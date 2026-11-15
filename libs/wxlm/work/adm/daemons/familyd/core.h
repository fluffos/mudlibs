// core.h - 门派核心功能和基础定义
// 由familyd.c包含

// 最近检查时间戳
int last_check = 0;

// 保存数据文件路径
public string query_save_file() 
{ 
    return DATA_DIR "familyd"; 
}

// 初始化核心数据
private void init_core_data()
{
    // 检查最近检查时间
    if(!last_check)
        last_check = time();
}

// 更新日常检查时间
public void update_check_time()
{
    last_check = time();
} 