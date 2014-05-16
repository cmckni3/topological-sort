var exec = require('child_process').exec;

var sh = require('execSync').exec;

var fs = require('fs');

// TODO: Sample input actually has another possible 
// sort order. Need to take this into account in the test
var solution1 = "inDegrees = [0 0 1 2 1 2 2 1 ]\n\
Nodes with inDegree 0 [0, 1, ]\n\
reduced inDegrees = [0 0 1 1 0 2 2 1 ]\n\
reduced inDegrees = [0 0 1 1 0 1 2 1 ]\n\
reduced inDegrees = [0 0 0 0 0 1 2 1 ]\n\
reduced inDegrees = [0 0 0 0 0 0 1 0 ]\n\
reduced inDegrees = [0 0 0 0 0 0 1 0 ]\n\
reduced inDegrees = [0 0 0 0 0 0 0 0 ]\n\
reduced inDegrees = [0 0 0 0 0 0 0 0 ]\n\
reduced inDegrees = [0 0 0 0 0 0 0 0 ]\n\
1 4 0 3 7 5 6 2 \n\
";

var assert = require("assert");

describe('Topological Sort', function(){
  it('should compile', function(){
    sh('make clean && make');
    fs.existsSync('./tsort');
    assert.ok(fs.existsSync('./tsort'));
  });
  it('should topologically sort', function(done){
    exec('./tsort', function(err, stdout, stderr)
    {
      // assert.ok(stdout == solution1 || stdout == solution2);
      assert.equal(stdout, solution1);
      done();
    });
  });
});
