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

		Nan::SetPrototypeMethod(tpl, "GetToolId", GetToolId);
		Nan::SetPrototypeMethod(tpl, "GetToolNumber", GetToolNumber);
		Nan::SetPrototypeMethod(tpl, "OpenProject", OpenProject);

		constructor().Reset(Nan::GetFunction(tpl).ToLocalChecked());
		Nan::Set(target, Nan::New("AptStepMaker").ToLocalChecked(), Nan::GetFunction(tpl).ToLocalChecked());

}

NAN_METHOD(AptStepMaker::GetToolId)
{
		AptStepMaker * apt = Nan::ObjectWrap::Unwrap<AptStepMaker>(info.This());
		if (apt == 0) //Throw exception
				return;
		if (info.Length() != 1) //Function should get one argument.
				return;
		if (!info[0]->IsString())
				return;
		char * tlNum = 0;
		size_t tlNumLength = v8StringToChar(info[0], tlNum);
		int tl_id;
		if (!apt->_apt->get_tool_id(tlNum, tl_id)) //TODO: Handle error
				return;
		info.GetReturnValue().Set(tl_id);
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
		int id = info[0]->Int32Value();
		const char * tlNum;
		if (!apt->_apt->get_tool_number(id, tlNum)) //TODO: Handle Error
				return;
		info.GetReturnValue().Set(CharTov8String((char *)tlNum));
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
		ssize_t fnamelen = v8StringToChar(info[0], fname);
		if (!apt->_apt->read_238_file(fname)) //TODO: Handle Error.
				return;
		return; //Success finding, return.
}
