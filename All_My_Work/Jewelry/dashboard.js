document.addEventListener("DOMContentLoaded", () => {
    const visitors = parseInt(localStorage.getItem("visits")) || 0;
    const orders = JSON.parse(localStorage.getItem("orders")) || [];
  
    document.getElementById("visitor-count").innerText = visitors;
    document.getElementById("order-count").innerText = orders.length;
  
    const orderListHTML = orders.map(order => `
      <div style="margin-bottom: 10px;">
        <strong>Product:</strong> ${order.productName}<br>
        <strong>Total:</strong> Tk ${order.total}<br>
        <strong>Payment:</strong> ${order.paymentMethod}<br>
        <strong>Date:</strong> ${order.date}
      </div>
    `).join("");
  
    document.getElementById("order-list").innerHTML = orderListHTML;
  });
  const orders = JSON.parse(localStorage.getItem("orders") || "[]");

document.getElementById("order-count").innerText = orders.length;

const orderListHTML = orders.map(order => `
  <p>Product: ${order.productName}, Payment: ${order.paymentMethod}, Total: ${order.total}</p>
`).join("");

document.getElementById("order-list").innerHTML = orderListHTML;
