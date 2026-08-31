#ifndef __OBJECT_MODULE_H__
#define __OBJECT_MODULE_H__

private void valid_module_name(string module_name, int index);
private void valid_function_name(string function_name, int index);
private void detach_and_destruct(object mod);

public varargs object add_module(string module_file, mixed args...);
public mixed query_module(string module_name);
public int remove_module(string module_name);
public varargs int remove_module_instance(object mod);
public mapping query_modules();
public varargs mixed module(string module_name, string function_name, mixed args...);
public void remove_all_modules();

#endif // __OBJECT_MODULE_H__
