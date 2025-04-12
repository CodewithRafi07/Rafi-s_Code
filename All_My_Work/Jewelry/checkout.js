window.onload = function () {
    const productName = localStorage.getItem('productName');
    const productPrice = localStorage.getItem('productPrice');
    const productImage = localStorage.getItem('productImage');
  
    if (productName && productPrice && productImage) {
      document.getElementById('product-name').innerText = productName;
      document.getElementById('product-price').innerText = productPrice;
      document.getElementById('product-image').src = productImage;
    } else {
      document.getElementById('checkout-product').innerHTML = "No product selected.";
    }
  };
  