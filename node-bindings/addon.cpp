// addon.cc
#include <node.h>
#include <node_object_wrap.h>
#include "tsort-binding.h"

using namespace v8;

void CreateObject(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);
  TSortBinding::NewInstance(args);
}

void Add(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

  TSortBinding* obj1 = node::ObjectWrap::Unwrap<TSortBinding>(
      args[0]->ToObject());
  TSortBinding* obj2 = node::ObjectWrap::Unwrap<TSortBinding>(
      args[1]->ToObject());

  double sum = obj1->value() + obj2->value();
  args.GetReturnValue().Set(Number::New(isolate, sum));
}

void InitAll(Handle<Object> exports) {
  TSortBinding::Init();

  NODE_SET_METHOD(exports, "createObject", CreateObject);
  NODE_SET_METHOD(exports, "add", Add);
}

NODE_MODULE(addon, InitAll)
