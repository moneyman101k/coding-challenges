module.exports = function deserialize(string) {
  return new Buffer(string, 'base64').toString('utf8');
};
