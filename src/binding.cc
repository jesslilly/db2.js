#define BUILDING_NODE_EXTENSION
#include <node.h>
#include "connection.hh"

using namespace v8;

Handle<Value> Connect(const Arguments& args) {
  HandleScope scope;
  return scope.Close(Connection::Connect(args));
}

void InitAll(Handle<Object> target) {
  Connection::Init();

  target->Set(String::NewSymbol("connect"),
      FunctionTemplate::New(Connect)->GetFunction());
}

NODE_MODULE(db2, InitAll)
