#include "OnedsemevmApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<OnedsemevmApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

OnedsemevmApp::OnedsemevmApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  OnedsemevmApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  OnedsemevmApp::associateSyntax(_syntax, _action_factory);
}

OnedsemevmApp::~OnedsemevmApp()
{
}

// External entry point for dynamic application loading
extern "C" void OnedsemevmApp__registerApps() { OnedsemevmApp::registerApps(); }
void
OnedsemevmApp::registerApps()
{
  registerApp(OnedsemevmApp);
}

// External entry point for dynamic object registration
extern "C" void OnedsemevmApp__registerObjects(Factory & factory) { OnedsemevmApp::registerObjects(factory); }
void
OnedsemevmApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void OnedsemevmApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { OnedsemevmApp::associateSyntax(syntax, action_factory); }
void
OnedsemevmApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
