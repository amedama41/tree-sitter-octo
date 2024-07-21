module.exports = grammar({
  name: 'octo',

  rules: {
    document: $ => seq($.title, $.markdown_block),
  },

  externals: $ => [
    $.title,
    $.markdown_block,
  ],
});
