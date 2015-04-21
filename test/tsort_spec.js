var assert = require("assert");
var exec   = require('child_process').exec;
var fs     = require('fs');
var path   = require('path');

var async  = require('async');

// TODO: Sample input actually has another possible 
// sort order. Need to take this into account in the test
var solution1 = fs.readFileSync(path.resolve(__dirname, 'fixtures', 'solution1.txt'), 'UTF8');

describe('Topological Sort', function(){
  it('should compile', function(done){
    async.series([
      function(cb) {
        exec('make clean && make', function(err, stdout, stderr){
          if (err) return cb(err, null);
          cb(null, stdout);
        });
      }
    ], function(err, result){
      assert.ok(fs.existsSync('./tsort'));
      done();
    });
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

