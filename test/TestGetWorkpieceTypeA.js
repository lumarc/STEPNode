var StepNC = require('../build/Release/StepNC');
var globals = require('./testglobals');
var find = globals.find;
var tol = globals.tol;
var apt = globals.apt;

var expect = require("chai").expect;

describe("Test A GetWorkpieceType", function(){
	describe("Correct Return Value", function(){
		it("returns a list of tolerance ids", function() {

		    var wp = find.GetWorkpieceAll();
			
		    for (var i=0;i<wp.length;i++) {
			var pieces = find.GetWorkpieceSubAssemblyAll(wp[i]);

			for (var j=0; j<pieces.length; j++) {
			    var wp_type = find.GetWorkpieceType(pieces[j]);
			    expect(wp_type).to.be.a('string');
			}
		    }
	    });
	});
});
