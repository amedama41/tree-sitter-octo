module.exports = grammar({
  name: 'octo',

  rules: {
    document: $ => seq($.title, $.markdown_block),
    title: $ => seq($._line, '\n'),
    markdown_block: $ => repeat1(seq($._line, '\n')),
    _line: $ => /[^\r\n]*/,
  }
});
