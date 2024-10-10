<h1><u>DOMify</u></h1>

<h2>What is <b><u>DOM</u></b>?</h2>

Document Object Model(DOM) is the modelling of an HTML/XML document as a hierarchical tree structure wherein each node is an object representing a part of the document.

<h2>DOM in rendering web pages</h2>
To render a document such as a HTML page, most web browsers use an internal model similar to the DOM. The nodes of every document are organized in a tree structure, called the DOM tree, with the topmost node (a.k.a root node) named as "Document object". When an HTML page is rendered in browsers, the browser downloads the HTML into local memory and automatically parses it to display the page on screen.

<h2>Elements as nodes</h2>
- Each element node has a tag name, attributes, and can contain other element nodes or text nodes as children.
- Text content within an element is represented as a text node in the DOM tree. They always appear as leaf nodes in the DOM tree.
- Attributes of an element are represented as properties of the element node in the DOM tree.

<h2>An example</h2>
<b>HTML Code</b>

```html
<html>
  <head>
    <title>My Website</title>
  </head>
  <body>
    <h1>Welcome</h1>
    <p>This is my website.</p>
    <a href="https://example.com">Link</a>
  </body>
</html>
```

<br>

<b>DOM tree</b>

```
- Document (root)
  - html
    - head
      - title
        - "My Website"
    - body
      - h1
        - "Welcome"
      - p
        - "This is my website."
      - a
        - href: "https://example.com"
        - "Link"
```

<h2>Manipulating the DOM tree</h2>
The DOM tree can be manipulated using JavaScript or other programming languages. Common tasks include navigating the tree, adding, removing, and modifying nodes, and getting and setting the properties of nodes. The DOM API provides a set of methods and properties to perform these operations, such as <b>getElementById</b>, <b>createElement</b>, <B>appendChild</B>, and <B>innerHTML</B>.

<h2>References</h2>
https://en.wikipedia.org/wiki/Document_Object_Model
