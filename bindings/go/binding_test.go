package tree_sitter_octo_test

import (
	"testing"

	tree_sitter "github.com/smacker/go-tree-sitter"
	"github.com/tree-sitter/tree-sitter-octo"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_octo.Language())
	if language == nil {
		t.Errorf("Error loading Octo grammar")
	}
}
