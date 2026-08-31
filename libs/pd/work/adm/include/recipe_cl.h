#ifndef __RECIPE_CL_H__
#define __RECIPE_CL_H__

class RecipeStep {
  int time;
  string combine_method;
  string *required_materials;
  string *prohibited_materials;
  string *allowed_temperatures;
  string failure_yield;
};

class Recipe {
  string name;
  string type;
  string yield_file;
  mapping user_requirements;
  class RecipeStep *steps;
};

#endif
