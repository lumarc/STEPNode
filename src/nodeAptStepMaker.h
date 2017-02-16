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
//
// Author: Samson Bonfante (bonfante@steptools.com)
//

#pragma once
#include <nan.h>
#include <stncapt/APT.h>
#include <stncapt/message.h>
class AptStepMaker : public Nan::ObjectWrap {
private:
    apt2step * _apt;
    static AptStepMaker* _singleton;
    static NAN_METHOD(New);
    static inline Nan::Persistent<v8::Function> & constructor() {
	static Nan::Persistent<v8::Function> my_constructor;
	return my_constructor;
    }
    AptStepMaker() { 
        report_via_printf();
        _apt = new apt2step(); 
    };
    ~AptStepMaker() { delete _apt; };
public:
    static apt2step* getApt();
    static NAN_MODULE_INIT(Init);

    //int GetToolEID(string tool_number)
    static NAN_METHOD(GetToolEID);

    //string GetToolIdentifier(string tool_number)
    static NAN_METHOD(GetToolIdentifier);
		
    static NAN_METHOD(GetExecutableWorkpieceToBe);
		
    static NAN_METHOD(GetCurrentWorkpiece);
		
    static NAN_METHOD(GetCurrentWorkplan);
		
    static NAN_METHOD(GetWorkplanSetup);

    //string GetToolNumber(int id)
    static NAN_METHOD(GetToolNumber);

    //string GetUUID(int EID)
    static NAN_METHOD(GetUUID);

    //int[] GetWorkpieceExecutableAll(int wp_id)
    static NAN_METHOD(GetWorkpieceExecutableAll);
		
    static NAN_METHOD(GetWorkpiecePlacement);

    static NAN_METHOD(OpenProject);

    // void OpenSTEP (string file_name)
    static NAN_METHOD(OpenSTEP);

    //void Reset()
    static NAN_METHOD(Reset);

    //void ArcABC(string label,double new_x,double new_y,double new_z,double cx,double cy,double cz,double radius,bool ccw,double a,double b,double c)
    static NAN_METHOD(ArcABC);
	
    //void ArcGeneralPlane(string label,double new_x,double new_y,double new_z,double cx,double cy,double cz,double ci, double cj,double ck, double ca,double cb,double cc, double radius,bool ccw)
    static NAN_METHOD(ArcGeneralPlane);

    //void ArcRefABC(string label, double x,double y,double z,double cx,double cy,double cz,double radius,bool ccw,double a,double b,double c)
    static NAN_METHOD(ArcRefABC);

    //void ArcXYPlane(string label,double new_x,double new_y,double new_z,double cx,double cy,double cz,double radius,bool ccw)
    static NAN_METHOD(ArcXYPlane);

    //void ArcYZPlane(string label,double new_x,double new_y,double new_z,double cx,double cy,double cz,double radius,bool ccw)
    static NAN_METHOD(ArcYZPlane);

    //void ArcZXPlane(string label,double new_x,double new_y,double new_z,double cx,double cy,double cz,double radius,bool ccw)
    static NAN_METHOD(ArcZXPlane);

    //void CamModeOn()
    static NAN_METHOD(CamModeOn);
    
    //void CamModeOff()
    static NAN_METHOD(CamModeOff);
    
    //void CenterOn()
    static NAN_METHOD(CenterOn);

    //void ChangeWorkingstepTool(int ws_eid,int tl_eid)
    static NAN_METHOD(ChangeWorkingstepTool);

    //void CircleGeneralPlane(string label, double cx, double cy, double cz, double ci, double cj, double ck, double ca, double cb, double cc, double radius, bool ccw)
    static NAN_METHOD(CircleGeneralPlane);

    //void CircleXYPlane(string label, double cx, double cy, double cz, double radius, bool ccw)
    static NAN_METHOD(CircleXYPlane);

    //void CircleYZPlane(string label, double cx, double cy, double cz, double radius, bool ccw)
    static NAN_METHOD(CircleYZPlane);

    //void CircleZXPlane(string label, double cx, double cy, double cz, double radius, bool ccw)
    static NAN_METHOD(CircleZXPlane);

    //void Clean()
    static NAN_METHOD(Clean);

    //void ClearancePlane(double z_coordinate)
    static NAN_METHOD(ClearancePlane);

    //int CompressTechnology()
    static NAN_METHOD(CompressTechnology);

    //void Connector()
    static NAN_METHOD(Connector);

    //void ContactOn()
    static NAN_METHOD(ContactOn);
    
    //void CoolantOn()
    static NAN_METHOD(CoolantOn);

    //void CoolantOff()
    static NAN_METHOD(CoolantOff);

    //void CoolantMist()
    static NAN_METHOD(CoolantMist);

    //void CutterDiameterCompensationAssignment(double value)
    static NAN_METHOD(CutterDiameterCompensationAssignment);

    //void DefaultToInches()
    static NAN_METHOD(DefaultToInches);

    //void DefaultToMillimeters()
    static NAN_METHOD(DefaultToMillimeters);

    //void DefineTool(double diameter, double radius, double horizontal_distance, double vertical_distance, double unused, double angle, double height)
    static NAN_METHOD(DefineTool);

    //void DefineToolCoolantThrough(bool on_off)
    static NAN_METHOD(DefineToolCoolantThrough);

    //void DefineToolDrill(double diameter, double overall_assembly_length, double functional_length, double max_depth_of_cut, double point_angle)
    static NAN_METHOD(DefineToolDrill);

    //void DefineToolEndmill(double diameter, double overall_assembly_length, double functional_length, double max_depth_of_cut, double num_effective_teeth, double cutting_edge_angle)
    static NAN_METHOD(DefineToolEndmill);

    //void DefineToolFacemill(double diameter, double overall_assembly_length, double functional_length, double max_depth_of_cut, double num_effective_teeth, double cutting_edge_angle)
    static NAN_METHOD(DefineToolFacemill);

    //void DefineToolFeedAndSpeed(double feedrate, double spindle_speed)
    static NAN_METHOD(DefineToolFeedAndSpeed);

    //void DefineToolHandOfCut(string left_right_or_neutral)
    static NAN_METHOD(DefineToolHandOfCut);

    //void DefineToolMaterial(string standard_identifier, string material_identifier)
    static NAN_METHOD(DefineToolMaterial);

    //void DefineToolRadius(double radius)
    static NAN_METHOD(DefineToolRadius);

    //void DefineToolRotatingBoringCuttingTool(double diameter, double overall_assembly_length, double functional_length, double max_depth_of_cut)
    static NAN_METHOD(DefineToolRotatingBoringCuttingTool);

    //void DefineToolSpotDrill(double diameter, double overall_assembly_length, double functional_length, double max_depth_of_cut, double point_angle)
    static NAN_METHOD(DefineToolSpotDrill);

    //void DefineToolStraightReamer(double diameter, double overall_assembly_length, double functional_length, double max_depth_of_cut)
    static NAN_METHOD(DefineToolStraightReamer);

    //void DefineToolTapping(double diameter, double overall_assembly_length, double functional_length, double max_depth_of_cut, string thread_form_type, double pitch, double size)
    static NAN_METHOD(DefineToolTapping);

    //void DeleteAllUnusedTools()
    static NAN_METHOD(DeleteAllUnusedTools);

    //void DeleteAllUnusedWorkpieces()
    static NAN_METHOD(DeleteAllUnusedWorkpieces);

    //void DeleteExecutable(int exe_id)
    static NAN_METHOD(DeleteExecutable);

    //void DeleteToolParameters(int tl_id)
    static NAN_METHOD(DeleteToolParameters);

    //void DeleteWorkpiece(int wp_id)
    static NAN_METHOD(DeleteWorkpiece);

    //void EmptyOperation()
    static NAN_METHOD(EmptyOperation);

    //void EndWorkplan()
    static NAN_METHOD(EndWorkplan);
    //void SaveAsModules(v8::String file_name);
    static NAN_METHOD(SaveAsModules);

    //void SaveAsP21(v8::String file_name);
    static NAN_METHOD(SaveAsP21);

    //void SetNameGet();
    static NAN_METHOD(SetNameGet);
};
