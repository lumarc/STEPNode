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

    //{top:{id:int,val:double},bot:{id:int,val:double},front:{id:int,val:double},back:{id:int,val:double},left:{id:int,val:double},right:{id:int,val:double}} EstimateDepths(int wp_or_sh_id)
    static NAN_METHOD(EstimateDepths);

    //void ExecutableMoveAfter(int exe_id, int index, int plan_id)
    static NAN_METHOD(ExecutableMoveAfter);

    //void ExecutableReuse(int exe_id);
    static NAN_METHOD(ExecutableReuse);

    //void ExecutableReuseAfter(int exe_id, int index, int plan_id)
    static NAN_METHOD(ExecutableReuseAfter);

    //int ExecutableToSelective(int exe_id)
    static NAN_METHOD(ExecutableToSelective);

    //void ExecutableWorkpieceAsIs(int ws_id, string filename)
    static NAN_METHOD(ExecutableWorkpieceAsIs);

    //void ExecutableWorkpieceRemoval(int ws_id, string filename)
    static NAN_METHOD(ExecutableWorkpieceRemoval);

    //void ExecutableWorkpieceReuseAsIs(int ws_id, int wp_id)
    static NAN_METHOD(ExecutableWorkpieceReuseAsIs);

    //void ExecutableWorkpieceReuseRemoval(int ws_id, int wp_id)
    static NAN_METHOD(ExecutableWorkpieceReuseRemoval);

    //void ExecutableWorkpieceReuseToBe(int ws_id, int wp_id)
    static NAN_METHOD(ExecutableWorkpieceReuseToBe);

    //void ExecutableWorkpieceToBe(int ws_id, string filename)
    static NAN_METHOD(ExecutableWorkpieceToBe);

    //void ExportAP238CC1(string filename)
    static NAN_METHOD(ExportAP238CC1);

    //void ExportAsAPT(string filename)
    static NAN_METHOD(ExportAsAPT);

    //void ExportAsDmisCNC(string filename)
    static NAN_METHOD(ExportAsDmisCNC);

    //void ExportAsDmisManual(string filename)
    static NAN_METHOD(ExportAsDmisManual);

    //void ExportAsESAB(string filename)
    static NAN_METHOD(ExportAsESAB);

    //void ExportAsHaas(string filename)
    static NAN_METHOD(ExportAsHaas);

    //void ExportAsHeidenhainAC(string filename)
    static NAN_METHOD(ExportAsHeidenhainAC);

    //void ExportAsHeidenhainBC(string filename)
    static NAN_METHOD(ExportAsHeidenhainBC);

    //void ExportAsMDSI(string filename)
    static NAN_METHOD(ExportAsMDSI);

    //void ExportAsOkuma(string filename)
    static NAN_METHOD(ExportAsOkuma);

    //void ExportAsSiemens(string filename)
    static NAN_METHOD(ExportAsSiemens);

    //void ExportCNC(string filename, string style)
    static NAN_METHOD(ExportCNC);

    //void ExportWorkpiece(int wp_id, string filename)
    static NAN_METHOD(ExportWorkpiece);

    //void ExtendedNcFunction(string label, string description)
    static NAN_METHOD(ExtendedNcFunction);

    //int ExtendedNcFunctionAfter(string label, string description, int index, int plan_id)
    static NAN_METHOD(ExtendedNcFunctionAfter);
    
    //void ExternalOperation(string filename)
    static NAN_METHOD(ExternalOperation);

    //void Feedrate(double speed)
    static NAN_METHOD(Feedrate);

    //void FeedrateCSS(double value,double max)
    static NAN_METHOD(FeedrateCSS);

    //void FeedrateUnit(string unit)
    static NAN_METHOD(FeedrateUnit);

    //void FirstPathStartAxis(double i, double j, double k)
    static NAN_METHOD(FirstPathStartAxis);

    //void FirstPathStartPoint(double x, double y, double z)
    static NAN_METHOD(FirstPathStartPoint);

    //void Fixture(string filename)
    static NAN_METHOD(Fixture);

    //void GeometryForTool(int tl_id,string filename)
    static NAN_METHOD(GeometryForTool);

    //void GeometryForToolNumber(string filename, int number)
    static NAN_METHOD(GeometryForToolNumber);

    //int GetCNCexportActualFlutes(int tl_id)
    static NAN_METHOD(GetCNCexportActualFlutes);

    //bool GetCNCexportExecIsEnabled(int ws_id)
    static NAN_METHOD(GetCNCexportExecIsEnabled);

    //bool GetCNCexportExecSpeedprofileActive(int ws_id)
    static NAN_METHOD(GetCNCexportExecSpeedprofileActive);

    //double GetCurrentFeed()
    static NAN_METHOD(GetCurrentFeed);

    //int GetCurrentFixture()
    static NAN_METHOD(GetCurrentFixture);

    //int GetCurrentFunction()
    static NAN_METHOD(GetCurrentFunction);

    //int GetCurrentLastExecutable()
    static NAN_METHOD(GetCurrentLastExecutable);

    //{x:double, y:double, z:double, i:double, j:double, k:double} GetCurrentLocation()
    static NAN_METHOD(GetCurrentLocation);

    //{i:double, j:double, k:double, ri:double, rj:double, rk:double) GetCurrentNormals()
    static NAN_METHOD(GetCurrentNormals);

    //int GetCurrentProject()
    static NAN_METHOD(GetCurrentProject);

    //int GetCurrentRawpiece()
    static NAN_METHOD(GetCurrentRawpiece);

    //double GetCurrentSpeed()
    static NAN_METHOD(GetCurrentSpeed);

    //double GetCurrentTech()
    static NAN_METHOD(GetCurrentTech);

    //int GetCurrentTool()
    static NAN_METHOD(GetCurrentTool);

    //int GetCurrentToolpath()
    static NAN_METHOD(GetCurrentToolpath);

    //int GetCurrentWorkingstep()
    static NAN_METHOD(GetCurrentWorkingstep);

    //int GetCurrentWorkpiece()
    static NAN_METHOD(GetCurrentWorkpiece);

    //int GetCurrentWorkplan()
    static NAN_METHOD(GetCurrentWorkplan);

    //bool GetExecutableIsEnabled(int exe_id)
    static NAN_METHOD(GetExecutableIsEnabled);

    //bool GetExecutableIsReachable(int exe_id)
    static NAN_METHOD(GetExecutableIsReachable);

    //int GetExecutableWorkpieceAsIs(int exe_id)
    static NAN_METHOD(GetExecutableWorkpieceAsIs);

    //int GetExecutableWorkpieceFixture(int exe_id)
    static NAN_METHOD(GetExecutableWorkpieceFixture);

    //int GetExecutableWorkpieceRemoval(int exe_id)
    static NAN_METHOD(GetExecutableWorkpieceRemoval);

    //int GetExecutableWorkpieceToBe(int exe_id)
    static NAN_METHOD(GetExecutableWorkpieceToBe);

    //int GetExecutableWorkpieceTool(int ws_id)
    static NAN_METHOD(GetExecutableWorkpieceTool);

    //int[] GetFrameDefinitionAll() [replaces GetFrameDefinitionAllCount/Next]
    static NAN_METHOD(GetFrameDefinitionAll);

    //int GetFrameDefinitionBestGuessForExecutable(int exe_id)
    static NAN_METHOD(GetFrameDefinitionBestGuessForExecutable);
    static NAN_METHOD(GetSetupAll);
    static NAN_METHOD(GetSetupBestGuessForExecutable);
    static NAN_METHOD(GetWorkpieceExecutableAll);
    static NAN_METHOD(GetWorkpiecePlacement);
    static NAN_METHOD(GetWorkpieceShapeAll);
    static NAN_METHOD(GoHome);
    static NAN_METHOD(GoHomeAfter);
    static NAN_METHOD(GoToXYZ);
    static NAN_METHOD(GoToXYZ_ABC);
    static NAN_METHOD(GoToXYZ_IJK);
    static NAN_METHOD(GoToXYZ_IJK_ABC);
    static NAN_METHOD(GoToXYZ_IJK_REF_ABC);
    static NAN_METHOD(ImportFanuc);
    static NAN_METHOD(ImportHaas);
    static NAN_METHOD(ImportSiemens);
    static NAN_METHOD(ImportToolParametersFromSTRL);
    static NAN_METHOD(ImportWorkingstepOperationFromSTRL);
    static NAN_METHOD(ImportWorkingstepPaths);
    static NAN_METHOD(ImportWorkpiecesFromSTRL);
    static NAN_METHOD(ImportWorkplanFromFile);
    static NAN_METHOD(ImportWorkplanFromSTRL);
    static NAN_METHOD(Inches);
    static NAN_METHOD(IndexTable);
    static NAN_METHOD(IndexTableAfter);
    static NAN_METHOD(IsToolDefined);
    static NAN_METHOD(Left);
    static NAN_METHOD(LoadTool);
    static NAN_METHOD(LoadToolWithLength);
    static NAN_METHOD(MergeFollowingWorkingstep);
    static NAN_METHOD(MergeFollowingWorkingstepAll);
    static NAN_METHOD(MergeWorkingstep);
    static NAN_METHOD(Millimeters);
    static NAN_METHOD(MultaxOn);
    static NAN_METHOD(MultaxOff);
    static NAN_METHOD(NestSelectiveAfter);
    static NAN_METHOD(NestWorkplan);
    static NAN_METHOD(NestWorkplanAfter);
    static NAN_METHOD(NewProjectWithCCandWP);
    static NAN_METHOD(Open224);
    static NAN_METHOD(Open224andMakeWorkingSteps);
    static NAN_METHOD(OpenCheckSTRL);
    static NAN_METHOD(OpenSTEP);
    static NAN_METHOD(OpenUsingSTRL);
    static NAN_METHOD(OptionalStop);
    static NAN_METHOD(OptionalStopAfter);
    static NAN_METHOD(PartNo);
    static NAN_METHOD(PPrint);
    static NAN_METHOD(PPrintAfter);
    static NAN_METHOD(RawpieceOfWorkpiece);
    static NAN_METHOD(ReadCatiaAPTclfile);
    static NAN_METHOD(ReadCatiaAptPlateClfile);
    static NAN_METHOD(ReadMax5APTclfile);
    static NAN_METHOD(ReadProeAPTclfile);
    static NAN_METHOD(ReadUgsAPTclfile);
    static NAN_METHOD(ReplaceMax5APTclfile);
    static NAN_METHOD(RetractPlane);
    static NAN_METHOD(Right);
    static NAN_METHOD(RunConfiguration);
    static NAN_METHOD(SaveAsModulesWithSTRL);
    static NAN_METHOD(SaveAsP21WithSTRL);
    static NAN_METHOD(SaveFastAsModules);
    static NAN_METHOD(SaveFastAsP21);
    static NAN_METHOD(SecondProject);
    static NAN_METHOD(SecondProjectTransform);
    static NAN_METHOD(SELCTLTool);
    static NAN_METHOD(SetCNCexportActualFlutes);
    static NAN_METHOD(SetCNCexportComments);
    static NAN_METHOD(SetCNCexportExecDisabled);
    static NAN_METHOD(SetCNCexportExecEnabled);
    static NAN_METHOD(SetCNCexportExecSpeedprofileActive);
    static NAN_METHOD(SetCNCexportInsertStopAfterWorkingstep);
    static NAN_METHOD(SetCNCexportMatrixOn);
    static NAN_METHOD(SetCNCexportMatrixOff);
    static NAN_METHOD(SetCNCexportNumberOfDigits);
    static NAN_METHOD(SetCNCexportProgramNum);
    static NAN_METHOD(SetCNCexportSpeedOverride);
    static NAN_METHOD(SetCNCexportToolOpts);
    static NAN_METHOD(SetCNCexportTraceability);
    static NAN_METHOD(SetCNCexportUnits);
    static NAN_METHOD(SetCNCexportUsingBlocknumbers);
    static NAN_METHOD(SetCNCexportUsingTCP);
    static NAN_METHOD(SetCNCexportWorkoffset);
    static NAN_METHOD(SetDebuggingNamesOn);
    static NAN_METHOD(SetDebuggingNamesOff);
    static NAN_METHOD(SetDefineArcUsingViaOn);
    static NAN_METHOD(SetDefineArcUsingViaOff);
    static NAN_METHOD(SetDirection);
    static NAN_METHOD(SetLocation);
    static NAN_METHOD(SetMaximumDeviation);
    static NAN_METHOD(SetModeMill);
    static NAN_METHOD(SetModeTurn);
    static NAN_METHOD(SetName);
    static NAN_METHOD(SetNameCheckSTRL);
    static NAN_METHOD(SetNameCreateSTRL);
    static NAN_METHOD(SetNameGetSTRL);
    static NAN_METHOD(SetNameHasSTRL);
    static NAN_METHOD(SetNameHitSTRL);
    static NAN_METHOD(SetNameSTRL);
    static NAN_METHOD(SetNameType);
    static NAN_METHOD(SetToolAutoNumberOn);
    static NAN_METHOD(SetToolAutoNumberOff);
    static NAN_METHOD(SetToolIdentifier);
    static NAN_METHOD(SetToolNumber);
    //has _force and _if_not_set
    static NAN_METHOD(SetUUID);
    static NAN_METHOD(Shutdown);
    static NAN_METHOD(SpindleSpeed);
    static NAN_METHOD(SpindleSpeedUnit);
    static NAN_METHOD(Stop);
    static NAN_METHOD(StopAfter);
    static NAN_METHOD(STRLCapture);
    static NAN_METHOD(STRLRestore);
    static NAN_METHOD(ToolGeometry);
    static NAN_METHOD(URLGet);
    static NAN_METHOD(URLHas);
    static NAN_METHOD(URLSet);
    static NAN_METHOD(UsingEnglishUnits);
    static NAN_METHOD(UsingFrenchUnits);
    static NAN_METHOD(Workingstep);
    static NAN_METHOD(WorkingstepAfter);
    static NAN_METHOD(WorkingstepOperationReuse);
    static NAN_METHOD(WorkingstepOperationReuseAfter);
    static NAN_METHOD(WorkingstepReuse);
    static NAN_METHOD(WorkingstepReuseAfter);
    static NAN_METHOD(WorkingstepToolpathOrientation);
    static NAN_METHOD(WorkingstepToolpathOrientationDelete);
    static NAN_METHOD(WorkingstepToolpathOrientationReuse);
    static NAN_METHOD(Workpiece);
    static NAN_METHOD(WorkpieceAndRawpiece);
    static NAN_METHOD(WorkpieceSecondPlacement);
    static NAN_METHOD(WorkplanFromSelective);
    static NAN_METHOD(WorkplanSetup);
    static NAN_METHOD(WorkplanSetupDelete);
    static NAN_METHOD(WorkplanSetupFixture);
    static NAN_METHOD(WorkplanSetupFixtureMountGet);
    static NAN_METHOD(WorkplanSetupFixtureMountPut);
    static NAN_METHOD(WorkplanSetupFixtureWorkpieceGet);
    static NAN_METHOD(WorkplanSetupFixtureWorkpiecePut);
    static NAN_METHOD(WorkplanSetupGet);
    static NAN_METHOD(WorkplanSetupPut);
    static NAN_METHOD(WorkplanToSelective);

	//void SaveAsModules(v8::String file_name);
	static NAN_METHOD(SaveAsModules);

    //void SaveAsP21(v8::String file_name);
    static NAN_METHOD(SaveAsP21);

    //void SetNameGet();
    static NAN_METHOD(SetNameGet);
};
