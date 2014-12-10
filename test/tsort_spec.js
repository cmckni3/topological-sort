var assert = require("assert");
var exec   = require('child_process').exec;
var sh     = require('execSync').exec;
var fs     = require('fs');
var path   = require('path');

// TODO: Sample input actually has another possible 
// sort order. Need to take this into account in the test
var solution1 = fs.readFileSync(path.resolve(__dirname, 'fixtures', 'solution1.txt'), 'UTF8');

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

