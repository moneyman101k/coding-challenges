module.exports = function serialize(client_id, item_id, institution_type) {
  return new Buffer(
    client_id + ',' + item_id + ',' + institution_type,
    'utf8'
  ).toString('base64');
};
