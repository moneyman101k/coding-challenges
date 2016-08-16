const deserialize = require('./deserialize_token');

process.argv.forEach(function (val, index, array) {
    if(index == 2){
        var deserial_token = deserialize(val);
        var split_token = deserial_token.split(',');
        // split_token[0] represents client_id, split_token[1] represents item_id
        // New Age Banking LLC client_id == "55f7076079cebe83d0b3cffd" 
        if(split_token[0] == '55f7076079cebe83d0b3cffd'){
            console.log(split_token[1]);
            fs.appendFile('question1_deserialize_newage_item_ids.txt', test_token + "\n", function(err) {
            });
        }
    }
});