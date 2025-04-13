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
  document.querySelector("button").addEventListener("click", function () {
    const selected = document.querySelector('input[name="payment"]:checked');
    const paymentMethod = selected ? selected.nextSibling.nodeValue.trim() : "None";
    const messageElement = document.getElementById("paymentMessage");
  
    if (paymentMethod === "Cash On Delivery") {
      messageElement.innerHTML = `
        <strong>অর্ডার কনফার্মড!</strong><br>
        আপনার অর্ডারটি সফলভাবে গ্রহণ করা হয়েছে। পেমেন্ট হবে ডেলিভারির সময়।
      `;
    } else {
      messageElement.innerHTML = `
        <strong>${paymentMethod} পেমেন্ট</strong><br>
        অনুগ্রহ করে ${paymentMethod} নম্বরে টাকা পাঠান:<br><br>
        <strong>নম্বর:</strong> 01XXXXXXXXX<br>
        <strong>রেফারেন্স:</strong> আপনার নাম<br><br>
        <em>ট্রানজ্যাকশন আইডি দিন আমাদের ফেসবুক ইনবক্সে।</em>
      `;
    }
  
    document.getElementById("paymentPopup").style.display = "block";
  });
  
  function closePopup() {
    document.getElementById("paymentPopup").style.display = "none";
  }
  document.querySelector("button").addEventListener("click", () => {
    const name = document.getElementById("product-name-summary").innerText;
    const price = document.getElementById("product-price-summary").innerText;
    const total = document.getElementById("totalPrice").innerText;
    const paymentMethod = document.querySelector('input[name="payment"]:checked').nextSibling.textContent.trim();
  
    const order = {
      productName: name,
      total: total,
      user: "Guest", // or use a form to ask name/email later
      paymentMethod,
      date: new Date().toLocaleString()
    };
  
    let orders = JSON.parse(localStorage.getItem("orders")) || [];
    orders.push(order);
    localStorage.setItem("orders", JSON.stringify(orders));
  });
  
  


  