var StepNC = require('../build/Release/StepNC');
var globals = require('./testglobals');
var find = globals.find;
var ms = new StepNC.machineState('model.stpnc');

var expect = require("chai").expect;

describe("Test A GetDeltaJSON", function(){
	describe("Correct Return Value", function(){
		it("returns a delta with the correct WS", function() {
			ms.GoToWS(127418);
			ms.NextWS();
			var delta = {};
			delta = JSON.parse(ms.GetDeltaJSON());
			expect(delta.workingstep).to.equal(128050);
		});
	});
});