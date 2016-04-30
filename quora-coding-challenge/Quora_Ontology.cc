// Quora Programming Challenge - Ontology
// Name: Maneesh Karipineni
// Date: 4/13/16

#include <iostream>
#include <stdlib.h>
#include <set>
#include <vector>
#include <string>
#include <sstream>

using namespace std;


class TreeNode {
  public:
    string name;
    vector<TreeNode*> children;
    vector<string> questions;

    TreeNode(string name){
      this->name = name;
    }

    void addQuestion(string topic, string question){
      if(topic == name){
        this->questions.push_back(question);
      }
      else {
        int i = 0;
        for(int i = 0; i < children.size(); i++){
          children[i]->addQuestion(topic, question);
        }
      }
    }

    int queryQuestions(string topic, string question){
      int count = 0;

      vector<TreeNode*> searchTopic;
      searchTopic.push_back(this);
      TreeNode* curr = *(searchTopic.end()-1);

      int i = 0;
      while(searchTopic.size() > 0){
        curr = *searchTopic.begin();
        if(curr->name == topic){
          vector<TreeNode*> toBeFulfilled;
          toBeFulfilled.push_back(this);
          TreeNode* curr = *(toBeFulfilled.end()-1);
          while(toBeFulfilled.size() > 0){
            curr = *(toBeFulfilled.begin());
            for(i = 0; i < curr->questions.size(); i++){
              if(curr->questions[i].substr(0, question.length()) == question){
                count++;
              }
            }
            for(i = 0; i < curr->children.size(); i++){
              toBeFulfilled.push_back(curr->children[i]);
            }
            toBeFulfilled.erase(toBeFulfilled.begin());
          }
          break;
        }
        for(i = 0; i < curr->children.size(); i++){
          searchTopic.push_back(curr->children[i]);
        }
        searchTopic.erase(searchTopic.begin());
      }
      return count;
    }

};



int createTree(TreeNode* head, int n){

  string line;
  getline(cin, line, '\n');
  istringstream line_iss(line);
  string topic_node;

  vector<TreeNode*> toBeFulfilled;
  toBeFulfilled.push_back(head);
  TreeNode* curr = *(toBeFulfilled.end()-1);

  while (n > 0) {
    getline(line_iss, topic_node, ' ');
    if (topic_node == "("){
      toBeFulfilled.push_back(*(curr->children.end()-1));
      curr = *(toBeFulfilled.end()-1);
    }
    else if (topic_node == ")") {
      toBeFulfilled.pop_back();
      curr = *(toBeFulfilled.end()-1);
    }
    else {
      TreeNode* new_child_topic = new TreeNode(topic_node);
      curr->children.push_back(new_child_topic);
      n--;
    }
  }

  return 0;
}




int main() {

  int n;
  char num_topics[1000];
  cin.getline(num_topics, 1000);
  n = atoi(num_topics);

  string topic_input;
  string topic_node;
  TreeNode* head = new TreeNode("head");
  createTree(head, n);

  int m;
  char num_questions[1000];
  cin.getline(num_questions, 1000);
  m = atoi(num_questions);\

  string topic_plus_question;
  for(int i = 0; i < m; ++i){
    getline(cin, topic_plus_question, '\n');
    istringstream complete_iss(topic_plus_question);
    string topic;
    getline(complete_iss, topic, ':');
    string question = topic_plus_question.substr(topic.size()+2, topic_plus_question.size()-topic.size()-2);
    head->addQuestion(topic, question);
  }

  int k;
  char num_queries[1000];
  cin.getline(num_queries, 1000);
  k = atoi(num_queries);

  string query;
  for(int j = 0; j < k; ++j){
    getline(cin, query, '\n');
    istringstream complete_iss(query);
    string topic_query;
    getline(complete_iss, topic_query, ' ');
    string question_query = query.substr(topic_query.size()+1, query.size()-topic_query.size()-1);
    cout << head->queryQuestions(topic_query, question_query) << endl;
  }

  return 0;
}