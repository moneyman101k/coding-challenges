var cheerio = require('cheerio');
var request = require('request');
var url_index = "http://extractor-interview.plaid.com/index";
var url_user_verify = 'http://extractor-interview.plaid.com/user/verify';
var u = "user_good";
var p = "pass_good";

var object = {username: u, password: p};

var j = request.jar();
request({url: url_index, jar: j, method: "GET"}, function(error, response, body){
	request.post({url: url_user_verify, jar: j, method: "POST", json: object}, function(error, response, body){
		$ = cheerio.load(body);

		var body_children = $("body").children();
		//console.log(body_children);

		var td_wrapper_children = body_children['2']["children"];
		//console.log(td_wrapper_children);

		var td_container_children = td_wrapper_children[1]['children'];
		//console.log(td_container_children);

		var td_layout_contentarea = td_container_children[27];
		// console.log(td_layout_contentarea);

		var td_layout_contentarea_children = td_container_children[27]['children'];
		//console.log(td_layout_contentarea_children);

		var role_main = td_layout_contentarea_children[5];
		// console.log(role_main);		

		var role_main_children = td_layout_contentarea_children[5]['children'];
		//console.log(role_main_children);

		var details_form = role_main_children[13];
		// console.log(details_form);

		var details_form_children = role_main_children[13]['children'];
		// console.log(details_form_children);

		var table = details_form_children[9];
		// console.log(table);

		var first_data = table['children'][3];
		var second_data = table['children'][5];

		var first_name = first_data['children'][1];
		var first_number = first_data['children'][3];
		var first_avail_balance = first_data['children'][9];

		var second_name = second_data['children'][1];
		var second_number = second_data['children'][3];
		var second_avail_balance = second_data['children'][9];

		console.log("\n");
		console.log("FIRST ACCOUNT INFO");
		console.log("account name: " + first_name['children'][0]['children'][0]['data'] + "\n"
					+ "account number: " + first_number['children'][0]['data'] + "\n"
					+ "account balance: " + first_avail_balance['children'][0]['data']);

		console.log("\n");
		console.log("SECOND ACCOUNT INFO");
		console.log("account name: " + second_name['children'][0]['children'][0]['data'] + "\n"
					+ "account number: " + second_number['children'][0]['data'] + "\n"
					+ "account balance: " + second_avail_balance['children'][0]['data']);
		console.log("\n");

	});
});