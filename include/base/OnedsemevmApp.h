#ifndef ONEDSEMEVMAPP_H
#define ONEDSEMEVMAPP_H

#include "MooseApp.h"

class OnedsemevmApp;

template<>
InputParameters validParams<OnedsemevmApp>();

class OnedsemevmApp : public MooseApp
{
public:
  OnedsemevmApp(InputParameters parameters);
  virtual ~OnedsemevmApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* ONEDSEMEVMAPP_H */
