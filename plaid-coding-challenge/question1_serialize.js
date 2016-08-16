var MongoClient = require('mongodb').MongoClient;
var assert = require('assert');
var url = 'mongodb://mkaripineni-interview.plaid.com:27017/platform-interview';
var fs = require('fs');
var stream = fs.createWriteStream("answer.txt");
const serialize = require('./serialize_token');
const deserialize = require('./deserialize_token');

var findItems = function(db, callback) {
    var cursor = db.collection('items').find();
    cursor.each(function(err, doc) {
	assert.equal(null, err);
        if(doc != null){
    	    var test_token = serialize(doc._id, doc._client, doc.institution_type);
    	    fs.appendFile('serialized_tokens.txt', test_token + "\n", function(err) {
    		  console.log(test_token);
    	    });
        }
        else {
	    callback();
        }
    });
};
stream.end();


MongoClient.connect(url, function(err, db) {
    assert.equal(null, err);
    findItems(db, function() {
	db.close();
    });
});
