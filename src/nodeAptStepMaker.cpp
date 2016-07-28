// $RCSfile: $
// $Revision: $ $Date: $
// Auth: Samson Bonfante (bonfante@steptools.com)
// 
// Copyright (c) 1991-2016 by STEP Tools Inc. 
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "nodeAptStepMaker.h"
#include "nodeUtils.h"
AptStepMaker* AptStepMaker::_singleton = nullptr;

apt2step* AptStepMaker::getApt() {
    if (_singleton == nullptr)
	_singleton = new AptStepMaker();
    return _singleton->_apt;
}

NAN_METHOD(AptStepMaker::New)
{

    if (info.IsConstructCall())
    {
	if (!info[0]->IsUndefined())
	{
	    return;
	}
	if (_singleton == nullptr)
	    _singleton = new AptStepMaker();
	_singleton->Wrap(info.This());
	info.GetReturnValue().Set(info.This());
    }
    else
    {
	return;
    }
}

NAN_MODULE_INIT(AptStepMaker::Init)
{
    v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
    tpl->SetClassName(Nan::New("AptStepMaker").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    Nan::SetPrototypeMethod(tpl, "GetToolEID", GetToolEID);
    Nan::SetPrototypeMethod(tpl, "GetToolIdentifier", GetToolIdentifier);
    Nan::SetPrototypeMethod(tpl, "GetToolNumber", GetToolNumber);
    Nan::SetPrototypeMethod(tpl, "GetUUID", GetUUID);
    Nan::SetPrototypeMethod(tpl, "GetWorkpieceExecutableAll", GetWorkpieceExecutableAll);
    Nan::SetPrototypeMethod(tpl, "GetWorkpiecePlacement", GetWorkpiecePlacement);
		Nan::SetPrototypeMethod(tpl, "GetExecutableWorkpieceToBe", GetExecutableWorkpieceToBe);
		Nan::SetPrototypeMethod(tpl, "GetCurrentWorkpiece", GetCurrentWorkpiece);
		Nan::SetPrototypeMethod(tpl, "GetCurrentWorkplan", GetCurrentWorkplan);
		Nan::SetPrototypeMethod(tpl, "GetWorkplanSetup", GetWorkplanSetup);
		Nan::SetPrototypeMethod(tpl, "OpenProject", OpenProject);
    Nan::SetPrototypeMethod(tpl, "OpenSTEP", OpenSTEP);
    Nan::SetPrototypeMethod(tpl, "SaveAsModules", SaveAsModules);
    Nan::SetPrototypeMethod(tpl, "SaveAsP21", SaveAsP21);
    Nan::SetPrototypeMethod(tpl, "SetNameGet", SetNameGet);

    constructor().Reset(Nan::GetFunction(tpl).ToLocalChecked());
    Nan::Set(target, Nan::New("AptStepMaker").ToLocalChecked(), Nan::GetFunction(tpl).ToLocalChecked());

}

NAN_METHOD(AptStepMaker::GetToolEID)
{
    AptStepMaker * apt = Nan::ObjectWrap::Unwrap<AptStepMaker>(info.This());
    if (apt == 0) //Throw exception
	return;
    if (info.Length() != 1) //Function should get one argument.
	return;
    if (!info[0]->IsString())
	return;
    char * toolNum = 0;
    v8StringToChar(info[0], toolNum);
    int toolEID;
    if (!apt->_apt->get_tool_id(toolNum, toolEID)) //TODO: Handle error
	return;
    info.GetReturnValue().Set(toolEID);
    return;
}

NAN_METHOD(AptStepMaker::GetToolIdentifier)
{
    AptStepMaker * apt = Nan::ObjectWrap::Unwrap<AptStepMaker>(info.This());
    if (apt == 0) //Throw Exception
	return;
    if (info.Length() != 1) //Function should get one argument.
	return;
    if (!info[0]->IsString())
	return;
    char * toolNum = 0;
    v8StringToChar(info[0], toolNum);
    const char * toolID = 0;
    if (!apt->_apt->get_tool_identifier(toolNum, toolID)) // TODO: Handle error
	return;
    info.GetReturnValue().Set(CharTov8String((char *)toolNum));
    return;
}

NAN_METHOD(AptStepMaker::GetToolNumber)
{
    AptStepMaker * apt = Nan::ObjectWrap::Unwrap<AptStepMaker>(info.This());
    if (apt == 0) //Throw Exception
	return;
    if (info.Length() != 1) //Function should get one argument.
	return;
    if (!info[0]->IsInt32())
	return;
    Nan::Maybe<int32_t> id = Nan::To<int32_t>(info[0]);
    const char * tlNum = 0;
    if (!apt->_apt->get_tool_number(id.FromJust(), tlNum)) //TODO: Handle Error
	return;
    info.GetReturnValue().Set(CharTov8String((char *)tlNum));
    return;
}

NAN_METHOD(AptStepMaker::GetUUID)
{
    AptStepMaker * apt = Nan::ObjectWrap::Unwrap<AptStepMaker>(info.This());
    if (apt == 0) //Throw Exception
	return;
    if (info.Length() != 1) //Function should get one argument.
	return;
    if (!info[0]->IsInt32())
	return;
    Nan::Maybe<int32_t> eid = Nan::To<int32_t>(info[0]);
    const char * uuid;
    if (!apt->_apt->get_uuid(eid.FromJust(), uuid)) //TODO: Handle error
	return;
    info.GetReturnValue().Set(CharTov8String((char *)uuid));
    return;
}

NAN_METHOD(AptStepMaker::GetWorkpieceExecutableAll)
{
    AptStepMaker * apt = Nan::ObjectWrap::Unwrap<AptStepMaker>(info.This());
    if (apt == 0) //Throw Exception
    return;
    if (info.Length() != 1) //Function should get one argument.
    return;
    if (!info[0]->IsInt32())
    return;

    Nan::Maybe<int32_t> wpid = Nan::To<int32_t>(info[0]);
    int count = 0;
    if (!apt->_apt->workpiece_executable_count(wpid.FromJust(), count)) //Throw Exception
    return;
    
    v8::Local<v8::Array> array = Nan::New<v8::Array>();
    for (int i = 0; i < count; i++) {
        int exe_id = 0;
        if (!apt->_apt->workpiece_executable_next(wpid.FromJust(), i, exe_id)) //Throw Exception
            return;
        else
            array->Set(i, Nan::New(exe_id));
    }

    info.GetReturnValue().Set(array);
    return;
}

NAN_METHOD(AptStepMaker::GetWorkpiecePlacement) {
  AptStepMaker * apt = Nan::ObjectWrap::Unwrap<AptStepMaker>(info.This());
  if (apt == 0) //Throw Exception
  return;
  if (info.Length() != 1) //Function should get one argument.
  return;
  if (!info[0]->IsInt32())
  return;
	
	Nan::Maybe<int32_t> wpid = Nan::To<int32_t>(info[0]);
	double x;
	double y;
	double z;
	double i;
	double j;
	double k;
	double a;
	double b;
	double c;
	
  if (!apt->_apt->get_workpiece_placement(wpid.FromJust(), x, y, z, i, j, k, a, b, c)) //TODO: Handle error
		return;
		
  v8::Local<v8::Array> array = Nan::New<v8::Array>();
  array->Set(0, Nan::New(x));
	array->Set(1, Nan::New(y));
	array->Set(2, Nan::New(z));
	array->Set(3, Nan::New(i));
	array->Set(4, Nan::New(j));
	array->Set(5, Nan::New(k));
	array->Set(6, Nan::New(a));
	array->Set(7, Nan::New(b));
	array->Set(8, Nan::New(c));
	
  info.GetReturnValue().Set(array);
  return;
}

NAN_METHOD(AptStepMaker::GetExecutableWorkpieceToBe) {
  AptStepMaker * apt = Nan::ObjectWrap::Unwrap<AptStepMaker>(info.This());
  if (apt == 0) //Throw Exception
  return;
  if (info.Length() != 1) //Function should get one argument.
  return;
  if (!info[0]->IsInt32())
  return;
	
	Nan::Maybe<int32_t> wsid = Nan::To<int32_t>(info[0]);
	int wpid;
	
  if (!apt->_apt->executable_removal_workpiece(wsid.FromJust(), wpid)) //TODO: Handle error
		return;
	
  info.GetReturnValue().Set(wpid);
  return;
}

NAN_METHOD(AptStepMaker::GetCurrentWorkpiece) {
	
	AptStepMaker* apt = Nan::ObjectWrap::Unwrap<AptStepMaker>(info.This());
	
	int wsid;
	int dummy;
  if (!apt->_apt->more_current_ids(wsid, dummy, dummy, dummy, dummy)) //TODO: Handle error
		return;
	
  info.GetReturnValue().Set(wsid);
  return;
}

NAN_METHOD(AptStepMaker::GetCurrentWorkplan) {
	
	AptStepMaker* apt = Nan::ObjectWrap::Unwrap<AptStepMaker>(info.This());
	
	int wpid;
	int dummy;
  if (!apt->_apt->more_current_ids(dummy, wpid, dummy, dummy, dummy)) //TODO: Handle error
		return;
	
  info.GetReturnValue().Set(wpid);
  return;
}

NAN_METHOD(AptStepMaker::GetWorkplanSetup) {
  AptStepMaker * apt = Nan::ObjectWrap::Unwrap<AptStepMaker>(info.This());
  if (apt == 0) //Throw Exception
  return;
  if (info.Length() != 1) //Function should get one argument.
  return;
  if (!info[0]->IsInt32())
  return;
	
	Nan::Maybe<int32_t> wpid = Nan::To<int32_t>(info[0]);
	double x;
	double y;
	double z;
	double i;
	double j;
	double k;
	double a;
	double b;
	double c;
	
  if (!apt->_apt->workplan_setup_get(wpid.FromJust(), x, y, z, i, j, k, a, b, c)) //TODO: Handle error
		return;
		
  v8::Local<v8::Array> array = Nan::New<v8::Array>();
  array->Set(0, Nan::New(x));
	array->Set(1, Nan::New(y));
	array->Set(2, Nan::New(z));
	array->Set(3, Nan::New(i));
	array->Set(4, Nan::New(j));
	array->Set(5, Nan::New(k));
	array->Set(6, Nan::New(a));
	array->Set(7, Nan::New(b));
	array->Set(8, Nan::New(c));
	
  info.GetReturnValue().Set(array);
  return;
}

NAN_METHOD(AptStepMaker::OpenProject) {
    AptStepMaker* apt = Nan::ObjectWrap::Unwrap<AptStepMaker>(info.This());
    if (apt == 0) //Throw Exception
	return;
    if (info.Length() != 1) //Function should get one argument.
	return;
    if (!info[0]->IsString())
	return;
    char * fname = 0;
    v8StringToChar(info[0], fname);
    if (!apt->_apt->read_238_file(fname)) //TODO: Handle Error.
	return;
    return; //Success finding, return.
}

NAN_METHOD(AptStepMaker::OpenSTEP) {
    AptStepMaker* apt = Nan::ObjectWrap::Unwrap<AptStepMaker>(info.This());
    if (apt == 0) //Throw Exception
	return;
    if (info.Length() != 1) //Function should get one argument.
	return;
    if (!info[0]->IsString())
	return;
    char * fname = 0;
    v8StringToChar(info[0], fname);
    if (!apt->_apt->read_203_file(fname)) //TODO: Handle Error.
	return;
    return; //Success finding, return.
}

NAN_METHOD(AptStepMaker::SaveAsModules)
{
    AptStepMaker * apt = Nan::ObjectWrap::Unwrap<AptStepMaker>(info.This());
    if (apt == 0) //Throw Exception
	return;

    if (info[0]->IsUndefined())
	return;

    if (!info[0]->IsString())
	return;

    char* file_name_utf8;
    v8StringToChar(info[0], file_name_utf8);


    if (!apt->_apt->save_file(file_name_utf8, true)) //Throw Exception
	return;
}




NAN_METHOD(AptStepMaker::SaveAsP21)
{
    AptStepMaker * apt = Nan::ObjectWrap::Unwrap<AptStepMaker>(info.This());
    if (apt == 0) //Throw Exception
	return;

    if (info[0]->IsUndefined())
	return;

    if (!info[0]->IsString())
	return;

    char* file_name_utf8;
    v8StringToChar(info[0], file_name_utf8);


    if (!apt->_apt->save_file(file_name_utf8, false)) //Throw Exception
	return;
}

NAN_METHOD(AptStepMaker::SetNameGet)
{
    AptStepMaker * apt = Nan::ObjectWrap::Unwrap<AptStepMaker>(info.This());
    if (apt == 0) //Throw Exception
    return;
    if (info.Length() != 1) //Function should get one argument.
    return;
    if (!info[0]->IsInt32())
    return;
    Nan::Maybe<int32_t> eid = Nan::To<int32_t>(info[0]);
    const char * szName;
    if (!apt->_apt->get_name(eid.FromJust(), szName)) //TODO: Handle error
    return;
    info.GetReturnValue().Set(CharTov8String((char *)szName));
    return;
}