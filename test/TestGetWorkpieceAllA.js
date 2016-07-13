var StepNC = require('../build/Release/StepNC');
var globals = require('./testglobals');
var find = globals.find;
var tol = globals.tol;
var apt = globals.apt;

find.OpenProject("boxy-5.stpnc");

var expect = require("chai").expect;

describe("Test A GetWorkpieceAll", function(){
	describe("Correct Return Value", function(){
		it("returns a list of workpiece ids", function() {
			var workpieces = find.GetWorkpieceAll();

			expect(workpieces.length).to.be.above(0);
		});
	});
});
